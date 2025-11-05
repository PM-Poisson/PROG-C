/* couleur.h
 * Objectif : définition d'une couleur RGB(A) et utilitaires.
 */

#ifndef COULEUR_H
#define COULEUR_H

#include <stddef.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Couleur;

/* Convertit une couleur en chaîne hex "#RRGGBB" (buf >= 8) */
void couleur_to_hex(const Couleur *c, char *buf, size_t bufsize);

/* Convertit "#RRGGBB" en Couleur (retourne 0 si ok, -1 si erreur) */
int hex_to_couleur(const char *hex, Couleur *out);

#endif
