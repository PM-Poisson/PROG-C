/* bmp.h
 * Fonctions pour lire BMP 24-bit non compressé et extraire couleurs.
 */

#ifndef BMP_H
#define BMP_H

#include "couleur.h"

/* Extrait les premières couleurs distinctes (dans l'ordre d'apparition)
 * Retourne le nombre de couleurs extraites (<= max_colors), ou -1 si erreur.
 */
int bmp_extract_first_colors(const char *path, Couleur *out_colors, int max_colors);

#endif
