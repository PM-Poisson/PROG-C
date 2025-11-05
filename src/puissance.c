#include <stdio.h>

int main() {
    int a = 2;   // base
    int b = 3;   // exposant
    int resultat = 1;

    // Cas particulier : exposant négatif (non géré en entier)
    if (b < 0) {
        printf("L'exposant negatif n'est pas pris en charge en entier.\n");
        return 0;
    }

    // Calcul de a^b avec une boucle
    for (int i = 0; i < b; i++) {
        resultat *= a;
    }

    printf("%d puissance %d = %d\n", a, b, resultat);

    return 0;
}
