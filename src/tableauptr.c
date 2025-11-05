#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 11  // Taille des tableaux

int main() {
    int tabInt[SIZE];
    float tabFloat[SIZE];

    srand(time(NULL)); // Initialiser la graine pour rand()

    // --- Remplissage des tableaux avec des valeurs aléatoires ---
    for (int i = 0; i < SIZE; i++) {
        *(tabInt + i) = rand() % 101;           // valeurs entre 0 et 100
        *(tabFloat + i) = (rand() % 1000) / 100.0f; // valeurs entre 0.00 et 9.99
    }

    // --- Affichage avant multiplication ---
    printf("Tableau d'entiers (avant multiplication par 3) :\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(tabInt + i));
    }
    printf("\n");

    printf("Tableau de float (avant multiplication par 3) :\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f ", *(tabFloat + i));
    }
    printf("\n");

    // --- Multiplication par 3 des valeurs dont l'indice est divisible par 2 ---
    for (int i = 0; i < SIZE; i += 2) {
        *(tabInt + i) *= 3;
        *(tabFloat + i) *= 3;
    }

    // --- Affichage après multiplication ---
    printf("\nTableau d'entiers (apres multiplication par 3) :\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(tabInt + i));
    }
    printf("\n");

    printf("Tableau de float (apres multiplication par 3) :\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f ", *(tabFloat + i));
    }
    printf("\n");

    return 0;
}
