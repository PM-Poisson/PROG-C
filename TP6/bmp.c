#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Helper: compare deux Couleur */
static int couleur_equal(const Couleur *a, const Couleur *b) {
    return a->r == b->r && a->g == b->g && a->b == b->b;
}

/* Implementation: read 24-bit BMP */
int bmp_extract_first_colors(const char *chemin, Couleur *colors, int max_colors) {
    FILE *f = fopen(chemin, "rb");
    if (!f) {
        perror("Erreur ouverture BMP");
        return -1;
    }

    unsigned char header[54];
    if (fread(header, 1, 54, f) != 54) {
        fprintf(stderr, "Erreur: en-tete BMP trop petit ou fichier invalide\n");
        fclose(f);
        return -1;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Erreur: pas un BMP valide\n");
        fclose(f);
        return -1;
    }

    /* offset to pixel data */
    unsigned int dataOffset = *(unsigned int*)&header[10];
    int width  = *(int*)&header[18];
    int height = *(int*)&header[22];
    unsigned short bpp = *(unsigned short*)&header[28];

    if (bpp != 24) {
        fprintf(stderr, "Erreur: seul BMP 24-bit non compressé est supporté (bpp=%u)\n", bpp);
        fclose(f);
        return -1;
    }

    /* goto pixel data */
    if (fseek(f, dataOffset, SEEK_SET) != 0) {
        perror("fseek");
        fclose(f);
        return -1;
    }

    /* BMP lines are padded to 4 bytes */
    int row_padded = (width*3 + 3) & (~3);
    unsigned char *row = (unsigned char*)malloc(row_padded);
    if (!row) { fclose(f); return -1; }

    int found = 0;
    /* BMP stores pixels bottom-up: iterate rows from bottom to top */
    for (int y = 0; y < abs(height) && found < max_colors; y++) {
        if (fread(row, 1, row_padded, f) != (size_t)row_padded) {
            fprintf(stderr, "Erreur lecture pixels\n");
            break;
        }
        /* iterate pixels left to right */
        for (int x = 0; x < width && found < max_colors; x++) {
            int idx = x*3;
            unsigned char b = row[idx + 0];
            unsigned char g = row[idx + 1];
            unsigned char r = row[idx + 2];

            /* check distinctness */
            int exists = 0;
            for (int k = 0; k < found; k++) {
                if (colors[k].r == r && colors[k].g == g && colors[k].b == b) {
                    exists = 1; break;
                }
            }
            if (!exists) {
                colors[found].r = r;
                colors[found].g = g;
                colors[found].b = b;
                found++;
            }
        }
    }

    free(row);
    fclose(f);
    return found;
}
