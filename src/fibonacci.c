#include <stdio.h>

int main() {
    int n;
    int U0 = 0, U1 = 1, Un;  // premiers termes

    // Demande à l'utilisateur
    printf("Entrez le nombre de termes a afficher : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Veuillez entrer un nombre positif.\n");
        return 0;
    }

    printf("Suite de Fibonacci (%d termes) :\n", n);

    // Afficher U0
    if (n >= 1) {
        printf("%d", U0);
    }

    // Afficher U1
    if (n >= 2) {
        printf(", %d", U1);
    }

    // Calculer et afficher les termes suivants
    for (int i = 2; i < n; i++) {
        Un = U0 + U1;     // formule Un = Un-1 + Un-2
        printf(", %d", Un);
        U0 = U1;          // décaler les termes
        U1 = Un;
    }

    printf("\n");
    return 0;
}
