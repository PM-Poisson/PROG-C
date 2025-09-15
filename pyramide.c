#include <stdio.h>

int main() {
    int n, i, j;

    // Demander la hauteur de la pyramide à l'utilisateur
    do {
        printf("Entrez la hauteur de la pyramide (1-20) : ");
        scanf("%d", &n);
    } while (n <= 0 || n > 20); // Limite pour éviter un affichage trop grand

    printf("\nPyramide de hauteur %d :\n\n", n);

    for (i = 1; i <= n; i++) {
        // Afficher les espaces avant les nombres pour centrer
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Afficher les nombres croissants de 1 à i
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Afficher les nombres décroissants de i-1 à 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Passer à la ligne suivante
        printf("\n");
    }

    printf("\nGeneration de la pyramide terminee.\n");

    return 0;
}
