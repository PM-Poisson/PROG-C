/* client.c
 * Client qui :
 *  - lit un BMP (chemin donné en argument)
 *  - demande à l'utilisateur combien de couleurs (<=30)
 *  - extrait N premières couleurs distinctes
 *  - envoie un message JSON {"code":"couleurs","valeurs":[ "#RRGGBB", ... ]} via socket UNIX
 *
 * Usage: ./client chemin/image.bmp
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "client.h"
#include "bmp.h"
#include "couleur.h"

#define SOCKET_PATH "/tmp/tp6_socket"
#define MAX_COLS 30
#define BUF_SIZE 8192

/* Petite fonction utilitaire pour construire JSON simple.
   On n'utilise pas de lib externe; format contrôlé. */
static void build_json_colors(char *buf, size_t bufsz, Couleur *cols, int n) {
    char tmp[16];
    size_t pos = 0;
    pos += snprintf(buf+pos, bufsz-pos, "{\"code\":\"couleurs\",\"valeurs\":[");
    for (int i=0;i<n;i++) {
        couleur_to_hex(&cols[i], tmp, sizeof(tmp));
        pos += snprintf(buf+pos, bufsz-pos, "\"%s\"%s", tmp, (i==n-1)?"":",");
        if (pos >= bufsz-100) break;
    }
    pos += snprintf(buf+pos, bufsz-pos, "]}");
}

/* Envoie la chaîne JSON au serveur via socket UNIX */
static int send_json_to_server(const char *json) {
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return -1; }

    struct sockaddr_un addr;
    memset(&addr,0,sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path)-1);

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sock);
        return -1;
    }

    size_t len = strlen(json);
    if (write(sock, json, len) != (ssize_t)len) { perror("write"); close(sock); return -1; }
    /* Optionally wait for acknowledgment (not required here). */
    close(sock);
    return 0;
}

int run_client(const char *bmp_path) {
    if (!bmp_path) { fprintf(stderr,"Usage: client <image.bmp>\n"); return 1; }

    int nb = 10;
    printf("Nombre de couleurs à extraire (1-%d) [default 10]: ", MAX_COLS);
    char line[64];
    if (fgets(line,sizeof(line),stdin)) {
        int t = atoi(line);
        if (t >= 1 && t <= MAX_COLS) nb = t;
    }

    Couleur cols[MAX_COLS];
    int found = bmp_extract_first_colors(bmp_path, cols, nb);
    if (found < 0) { fprintf(stderr,"Erreur lecture BMP\n"); return 1; }
    if (found < nb) {
        printf("Attention : seulement %d couleurs distinctes extraites.\n", found);
        nb = found;
    }

    printf("Couleurs extraites (%d):\n", nb);
    for (int i=0;i<nb;i++) {
        char hex[8];
        couleur_to_hex(&cols[i], hex, sizeof(hex));
        printf(" %s\n", hex);
    }

    char json[BUF_SIZE];
    build_json_colors(json, sizeof(json), cols, nb);
    printf("JSON à envoyer: %s\n", json);

    if (send_json_to_server(json) != 0) {
        fprintf(stderr,"Erreur envoi JSON au serveur\n");
        return 1;
    }

    printf("Message envoyé au serveur.\n");
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr,"Usage: %s chemin_image.bmp\n", argv[0]);
        return 1;
    }
    return run_client(argv[1]);
}
