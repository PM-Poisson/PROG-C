#include "couleur.h"
#include <stdio.h>

void couleur_to_hex(const Couleur *c, char *buf) {
    /* buf doit contenir au moins 8 octets: "#RRGGBB\0" */
    sprintf(buf, "#%02X%02X%02X", c->r, c->g, c->b);
}
