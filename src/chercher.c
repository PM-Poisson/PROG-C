#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

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

    // Demander à l'utilisateur de saisir un nombre à chercher
    int nombre_a_chercher;
    printf("Entrez un nombre a chercher (entre 1 et 1000) : ");
    scanf("%d", &nombre_a_chercher);
    
    // Chercher le nombre dans le tableau
    int trouve = 0; // Flag pour indiquer si le nombre est trouvé
    for (i = 0; i < TAILLE; i++) {
        if (tableau[i] == nombre_a_chercher) {
            trouve = 1; // Le nombre est trouvé
            break;
        }
    }

    // Afficher le résultat de la recherche
    if (trouve) {
        printf("Le nombre %d a ete trouve dans le tableau.\n", nombre_a_chercher);
    } else {
        printf("Le nombre %d n'a pas ete trouve dans le tableau.\n", nombre_a_chercher);
    }

    return 0;
}
