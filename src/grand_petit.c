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
        if ((i + 1) % 10 == 0) { // retour à la ligne tous les 10 nombres
            printf("\n");
        }
    }
    printf("\n");

    // Initialiser min et max avec la première valeur
    min = tableau[0];
    max = tableau[0];

    // Parcourir le tableau pour trouver min et max
    for (i = 1; i < TAILLE; i++) {
        if (tableau[i] < min) {
            min = tableau[i];
        }
        if (tableau[i] > max) {
            max = tableau[i];
        }
    }

    // Afficher les résultats
    printf("\nLe numero le plus grand est : %d\n", max);
    printf("Le numero le plus petit est : %d\n", min);

    return 0;
}
