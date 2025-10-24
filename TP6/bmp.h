#ifndef BMP_H
#define BMP_H

#include "couleur.h"

/* Extrait les N premières couleurs distinctes d'un BMP 24-bit.
   Retourne le nombre réel de couleurs extraites (<= max_colors), ou -1 en cas d'erreur.
   colors doit pointer vers un tableau de taille >= max_colors.
*/
int bmp_extract_first_colors(const char *chemin, Couleur *colors, int max_colors);

#endif
