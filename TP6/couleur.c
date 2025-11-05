/* couleur.c
 * Implémentation des utilitaires de couleurs.
 */

#include "couleur.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void couleur_to_hex(const Couleur *c, char *buf, size_t bufsize) {
    if (!buf || bufsize < 8) return;
    snprintf(buf, bufsize, "#%02X%02X%02X", c->r, c->g, c->b);
}

static int hexval(char ch) {
    if ('0' <= ch && ch <= '9') return ch - '0';
    if ('a' <= ch && ch <= 'f') return ch - 'a' + 10;
    if ('A' <= ch && ch <= 'F') return ch - 'A' + 10;
    return -1;
}

int hex_to_couleur(const char *hex, Couleur *out) {
    if (!hex || !out) return -1;
    if (hex[0] != '#') return -1;
    int r1 = hexval(hex[1]), r2 = hexval(hex[2]);
    int g1 = hexval(hex[3]), g2 = hexval(hex[4]);
    int b1 = hexval(hex[5]), b2 = hexval(hex[6]);
    if (r1<0||r2<0||g1<0||g2<0||b1<0||b2<0) return -1;
    out->r = (unsigned char)((r1<<4)|r2);
    out->g = (unsigned char)((g1<<4)|g2);
    out->b = (unsigned char)((b1<<4)|b2);
    out->a = 255;
    return 0;
}
