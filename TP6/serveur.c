/* serveur.c
 * Serveur UNIX domain socket qui :
 *  - attend une connexion client
 *  - lit un message JSON (codes pris en charge: "couleurs", "message", "calcule")
 *  - pour "couleurs": génère output.svg et l'ouvre (xdg-open/firefox)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>

#include "serveur.h"
#include "couleur.h"

#define SOCKET_PATH "/tmp/tp6_socket"
#define BUF_SIZE 16384
#define OUTPUT_SVG "output.svg"

/* Simple parser JSON adapté à notre format d'arrivée :
   { "code":"couleurs", "valeurs":["#RRGGBB", ...] }
   On renvoie code et un tableau de chaînes extraites (max 30).
*/
static int parse_json_colors(const char *json, char values[][16], int maxv) {
    if (!json) return -1;
    const char *p = strstr(json, "\"code\"");
    if (!p) return -1;
    /* find code value */
    p = strstr(json, "\"valeurs\"");
    if (!p) return -1;
    p = strchr(p, '[');
    if (!p) return -1;
    p++; /* after [ */
    int cnt = 0;
    while (*p && *p != ']') {
        while (*p && *p != '\"') p++;
        if (!*p || *p != '\"') break;
        p++;
        char tmp[16]; int i=0;
        while (*p && *p != '\"' && i < 15) { tmp[i++] = *p++; }
        tmp[i]=0;
        if (i>0 && cnt < maxv) strncpy(values[cnt], tmp, 16);
        cnt++;
        if (*p == '\"') p++;
    }
    return cnt;
}

/* génère un SVG simple contenant N barres colorées */
static int generate_svg_from_hexs(char hexs[][16], int n) {
    FILE *f = fopen(OUTPUT_SVG, "w");
    if (!f) { perror("open svg"); return -1; }
    int width = 900;
    int height = 60 + n * 60;
    fprintf(f,"<svg xmlns='http://www.w3.org/2000/svg' width='%d' height='%d'>\n", width, height);
    fprintf(f,"<rect width='100%%' height='100%%' fill='white'/>\n");
    for (int i=0;i<n;i++) {
        int y = 20 + i*60;
        fprintf(f,"<rect x='20' y='%d' width='%d' height='40' fill='%s' stroke='black'/>\n", y, width-200, hexs[i]);
        fprintf(f,"<text x='%d' y='%d' font-family='sans-serif' font-size='16' fill='black'>%s</text>\n", width-160, y+25, hexs[i]);
    }
    fprintf(f,"</svg>\n");
    fclose(f);
    return 0;
}

/* Try to open with xdg-open; if not available try firefox; best-effort. */
static void open_svg(const char *path) {
    char cmd[512];
    /* try xdg-open */
    if (system(NULL)) {
        snprintf(cmd, sizeof(cmd), "xdg-open %s >/dev/null 2>&1 &", path);
        int r = system(cmd);
        if (r != 0) {
            /* fallback to firefox */
            snprintf(cmd, sizeof(cmd), "firefox %s >/dev/null 2>&1 &", path);
            system(cmd);
        }
    }
}

int run_server(void) {
    int server_fd, client_fd;
    struct sockaddr_un addr;
    unlink(SOCKET_PATH); /* remove previous socket if present */

    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return 1; }

    memset(&addr,0,sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path)-1);

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) { perror("bind"); close(server_fd); return 1; }
    if (listen(server_fd, 5) < 0) { perror("listen"); close(server_fd); return 1; }

    printf("Serveur prêt, attente de connexion sur %s\n", SOCKET_PATH);

    for (;;) {
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) { perror("accept"); continue; }

        printf("Client connecté.\n");
        char buf[BUF_SIZE];
        ssize_t n = read(client_fd, buf, sizeof(buf)-1);
        if (n <= 0) { close(client_fd); continue; }
        buf[n]=0;

        /* Identify code */
        if (strstr(buf, "\"code\":\"couleurs\"")) {
            char values[30][16];
            int cnt = parse_json_colors(buf, values, 30);
            if (cnt <= 0) {
                fprintf(stderr,"Aucune couleur trouvée dans JSON.\n");
            } else {
                printf("Reçu %d couleurs. Génération SVG...\n", cnt);
                generate_svg_from_hexs(values, cnt);
                open_svg(OUTPUT_SVG);
                printf("SVG généré et ouvert.\n");
            }
        } else if (strstr(buf, "\"code\":\"message\"")) {
            /* parse simple message */
            const char *p = strstr(buf, "\"valeurs\"");
            if (p) {
                p = strchr(p, '[');
                if (p) {
                    const char *q = strchr(p+1, '\"');
                    if (q) {
                        q++;
                        char msg[512]; int i=0;
                        while (*q && *q != '\"' && i < 510) msg[i++]=*q++;
                        msg[i]=0;
                        printf("Message du client: %s\n", msg);
                    }
                }
            }
        } else if (strstr(buf, "\"code\":\"calcule\"")) {
            /* Very simple calc: values: ["+","23","45"] */
            char op=0; int a=0,b=0;
            const char *p = strstr(buf, "\"valeurs\"");
            if (p) {
                /* crude parse to extract tokens between quotes */
                const char *q = strchr(p, '[');
                if (q) {
                    q++;
                    char tok[3][64];
                    int ti=0;
                    while (*q && *q != ']' && ti<3) {
                        while (*q && *q != '\"') q++;
                        if (!*q) break;
                        q++;
                        char tmp[64]; int k=0;
                        while (*q && *q != '\"' && k<63) tmp[k++]=*q++;
                        tmp[k]=0;
                        strncpy(tok[ti++], tmp, 64);
                    }
                    if (ti>=3) {
                        op = tok[0][0];
                        a = atoi(tok[1]);
                        b = atoi(tok[2]);
                        int res = 0;
                        switch (op) {
                            case '+': res = a + b; break;
                            case '-': res = a - b; break;
                            case '*': res = a * b; break;
                            case '/': res = (b!=0)?(a/b):0; break;
                            case '%': res = (b!=0)?(a%b):0; break;
                            default: break;
                        }
                        printf("Calcul: %d %c %d = %d\n", a, op, b, res);
                        /* send back simple JSON response? not implemented, server is one-way here */
                    }
                }
            }
        } else {
            printf("Message inconnu reçu: %s\n", buf);
        }

        close(client_fd);
    }

    close(server_fd);
    unlink(SOCKET_PATH);
    return 0;
}

int main() { return run_server(); }
