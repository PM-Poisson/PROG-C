#include "client.h"
#include "bmp.h"
#include "couleur.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10
#define COLORS_FILE "colors.txt"
#define FLAG_FILE "colors_ready"

void write_colors_file(Couleur *cols, int n) {
    FILE *f = fopen(COLORS_FILE, "w");
    if (!f) { perror("open colors.txt"); return; }
    for (int i = 0; i < n; i++) {
        char hex[8];
        couleur_to_hex(&cols[i], hex);
        /* write one hex per line */
        fprintf(f, "%s\n", hex);
    }
    fclose(f);
    /* create flag file */
    FILE *flag = fopen(FLAG_FILE, "w");
    if (flag) fclose(flag);
}

void client_send_bmp(const char *bmp_path) {
    Couleur cols[MAX_COLORS];
    int n = bmp_extract_first_colors(bmp_path, cols, MAX_COLORS);
    if (n < 0) {
        fprintf(stderr, "Erreur extraction couleurs\n");
        return;
    }
    printf("Couleurs extraites : %d\n", n);
    for (int i = 0; i < n; i++) {
        char hex[8];
        couleur_to_hex(&cols[i], hex);
        printf("%s\n", hex);
    }
    write_colors_file(cols, n);
    printf("Les couleurs ont ete ecrites dans %s ; serveur peut les lire.\n", COLORS_FILE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s chemin_image.bmp\n", argv[0]);
        return 1;
    }
    client_send_bmp(argv[1]);
    return 0;
}
