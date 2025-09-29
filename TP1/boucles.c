#include <stdio.h>

int main() {
    int compteur;

    // Saisie de la taille du triangle
    do {
        printf("Entrez la taille du triangle (inférieure à 10) : ");
        scanf("%d", &compteur);
    } while (compteur >= 10 || compteur <= 0);

    printf("\nTriangle rectangle avec for :\n");

    for (int i = 1; i <= compteur; i++) {          // boucle pour chaque ligne
        for (int j = 1; j <= i; j++) {            // boucle pour chaque caractère
            if (i % 2 == 0) {                      // lignes paires : #
                printf("# ");
            } else {                               // lignes impaires : *
                printf("* ");
            }
        }
        printf("\n");
    }

    // Version avec while
    printf("\nTriangle rectangle avec while :\n");
    int i = 1;
    while (i <= compteur) {
        int j = 1;
        while (j <= i) {
            if (i % 2 == 0) {
                printf("# ");
            } else {
                printf("* ");
            }
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
