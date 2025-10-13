#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 15

int main() {
    int tableau[TAILLE];
    int i;
    int min, max;

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Remplir le tableau avec des nombres aléatoires entre 1 et 1000
    for (i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 1000 + 1; // valeurs entre 1 et 1000
    }

    // Affichage du tableau généré
    printf("Tableau genere :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%4d ", tableau[i]);
        if ((i + 1) % 5 == 0) { // retour à la ligne tous les 5 nombres
            printf("\n");
        }
    }
    printf("\n");

    // Trier le tableau en utilisant un algorithme de tri simple (tri à bulles)
    for (i = 0; i < TAILLE - 1; i++) {
        for (int j = i + 1; j < TAILLE; j++) {
            if (tableau[i] > tableau[j]) {
                // Échanger les valeurs
                int temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }

    // Affichage du tableau trié
    printf("Tableau trie :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%4d ", tableau[i]);
        if ((i + 1) % 5 == 0) { // retour à la ligne tous les 5 nombres
            printf("\n");
        }
    }

    return 0;
}
