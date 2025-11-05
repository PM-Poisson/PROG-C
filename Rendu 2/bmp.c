/* bmp.c
 * Lecture minimale de BMP 24-bit non compressé.
 * On parcourt les pixels en mémoire et on récupère les premières couleurs distinctes.
 */

#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Helper : compare deux couleurs (RGB) */
static int couleur_equal(const Couleur *a, const Couleur *b) {
    return a->r==b->r && a->g==b->g && a->b==b->b;
}

int bmp_extract_first_colors(const char *path, Couleur *out_colors, int max_colors) {
    if (!path || !out_colors || max_colors <= 0) return -1;

    FILE *f = fopen(path, "rb");
    if (!f) { perror("fopen BMP"); return -1; }

    unsigned char header[54];
    if (fread(header, 1, 54, f) != 54) { fclose(f); return -1; }

    if (header[0]!='B' || header[1]!='M') { fclose(f); return -1; }

    unsigned int dataOffset = *(unsigned int*)&header[10];
    int width  = *(int*)&header[18];
    int height = *(int*)&header[22];
    unsigned short bpp = *(unsigned short*)&header[28];

    if (bpp != 24) { fprintf(stderr,"BMP: only 24-bit supported (bpp=%u)\n", bpp); fclose(f); return -1; }

    if (fseek(f, dataOffset, SEEK_SET) != 0) { fclose(f); return -1; }

    int row_padded = (width*3 + 3) & (~3);
    unsigned char *row = (unsigned char*)malloc(row_padded);
    if (!row) { fclose(f); return -1; }

    int found = 0;
    /* BMP stored bottom-up usually; we simply read rows sequentially (bottom-up or top-down depending on header sign)
       We'll read abs(height) rows. */
    int h = height > 0 ? height : -height;
    for (int y = 0; y < h && found < max_colors; y++) {
        if (fread(row, 1, row_padded, f) != (size_t)row_padded) break;
        for (int x = 0; x < width && found < max_colors; x++) {
            int idx = x*3;
            unsigned char b = row[idx+0];
            unsigned char g = row[idx+1];
            unsigned char r = row[idx+2];
            Couleur c = { r, g, b, 255 };

            int exists = 0;
            for (int k=0;k<found;k++) if (couleur_equal(&out_colors[k], &c)) { exists = 1; break; }
            if (!exists) out_colors[found++] = c;
        }
    }

    free(row);
    fclose(f);
    return found;
}
