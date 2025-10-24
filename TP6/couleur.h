#ifndef COULEUR_H
#define COULEUR_H

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Couleur;

/* retourne une chaîne hex comme "#RRGGBB" dans buf (buf >= 8) */
void couleur_to_hex(const Couleur *c, char *buf);

#endif
