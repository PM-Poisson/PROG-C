#include "serveur.h"
#include "couleur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define COLORS_FILE "colors.txt"
#define FLAG_FILE "colors_ready"
#define OUTPUT_SVG "output.svg"

/* lit colors.txt et remplit colors_count; renvoie nombre lu */
static int read_colors(Couleur *cols, int maxc) {
    FILE *f = fopen(COLORS_FILE, "r");
    if (!f) return -1;
    char line[64];
    int k = 0;
    while (k < maxc && fgets(line, sizeof(line), f)) {
        /* remove newline */
        line[strcspn(line, "\r\n")] = '\0';
        unsigned int r,g,b;
        if (sscanf(line, "#%02x%02x%02x", &r, &g, &b) == 3) {
            cols[k].r = (unsigned char)r;
            cols[k].g = (unsigned char)g;
            cols[k].b = (unsigned char)b;
            k++;
        }
    }
    fclose(f);
    return k;
}

/* génère un SVG simple affichant les couleurs en barres horizontales */
static int generate_svg(Couleur *cols, int n) {
    FILE *f = fopen(OUTPUT_SVG, "w");
    if (!f) { perror("open svg"); return -1; }

    int width = 800;
    int height = 100 + n * 50;
    fprintf(f, "<svg xmlns='http://www.w3.org/2000/svg' width='%d' height='%d'>\n", width, height);
    fprintf(f, "<rect width='100%%' height='100%%' fill='white'/>\n");
    for (int i = 0; i < n; i++) {
        char hex[8];
        sprintf(hex, "#%02X%02X%02X", cols[i].r, cols[i].g, cols[i].b);
        int y = 20 + i*50;
        /* colored rectangle */
        fprintf(f, "<rect x='50' y='%d' width='700' height='40' fill='%s' stroke='black'/>\n", y, hex);
        /* text (hex code) */
        fprintf(f, "<text x='60' y='%d' font-family='sans-serif' font-size='16' fill='black'>%s</text>\n", y+25, hex);
    }
    fprintf(f, "</svg>\n");
    fclose(f);
    return 0;
}

void server_watch_and_render() {
    printf("Serveur: en attente du fichier %s ...\n", FLAG_FILE);
    while (1) {
        if (access(FLAG_FILE, F_OK) == 0) {
            /* read colors */
            Couleur cols[10];
            int n = read_colors(cols, 10);
            if (n <= 0) {
                fprintf(stderr, "Erreur lecture couleurs ou fichier vide\n");
            } else {
                printf("Serveur: lu %d couleurs. Generation SVG...\n", n);
                if (generate_svg(cols, n) == 0) {
                    /* lancer firefox (en background) */
                    char cmd[512];
                    snprintf(cmd, sizeof(cmd), "firefox %s &", OUTPUT_SVG);
                    system(cmd);
                    printf("Serveur: SVG genere (%s) et ouvert avec firefox.\n", OUTPUT_SVG);
                }
            }
            /* cleanup: remove files to allow next run */
            remove(COLORS_FILE);
            remove(FLAG_FILE);
            printf("Serveur: attente pour prochain fichier...\n");
        }
        sleep(1);
    }
}

int main() {
    server_watch_and_render();
    return 0;
}
