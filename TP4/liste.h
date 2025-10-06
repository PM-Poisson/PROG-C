#ifndef LISTE_H
#define LISTE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Structure représentant une couleur RGBA
struct couleur {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

// Élément de la liste simplement chaînée
struct element {
    struct couleur data;
    struct element *suivant;
};

// Structure représentant la liste de couleurs
struct liste_couleurs {
    struct element *tete;
};

// Prototypes
void init_liste(struct liste_couleurs *liste);
void insertion(struct couleur *coul, struct liste_couleurs *liste);
void parcours(struct liste_couleurs *liste);

#endif
