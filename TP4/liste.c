#include "liste.h"

// Initialisation de la liste
void init_liste(struct liste_couleurs *liste) {
    liste->tete = NULL;
}

// Insertion en tête de liste
void insertion(struct couleur *coul, struct liste_couleurs *liste) {
    struct element *nouveau = malloc(sizeof(struct element));
    if (nouveau == NULL) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    nouveau->data = *coul;
    nouveau->suivant = liste->tete;
    liste->tete = nouveau;
}

// Parcours et affichage de toutes les couleurs
void parcours(struct liste_couleurs *liste) {
    struct element *courant = liste->tete;
    int i = 1;

    if (courant == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    while (courant != NULL) {
        printf("Couleur %d : R=%02X, G=%02X, B=%02X, A=%02X\n",
               i++, courant->data.r, courant->data.g, courant->data.b, courant->data.a);
        courant = courant->suivant;
    }
}
