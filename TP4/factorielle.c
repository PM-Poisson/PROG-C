#include <stdio.h>

// Fonction récursive pour calculer la factorielle
int factorielle(int num) {
    if (num == 0) {
        printf("fact(0): 1\n");
        return 1;
    } else {
        int valeur = num * factorielle(num - 1);
        printf("fact(%d): %d\n", num, valeur);
        return valeur;
    }
}

int main() {
    int n;

    printf("=== Calcul de la factorielle ===\n");
    printf("Entrez un entier naturel : ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erreur : la factorielle n'est pas définie pour les entiers négatifs.\n");
        return 1;
    }

    int resultat = factorielle(n);
    printf("\nRésultat final : %d! = %d\n", n, resultat);

    return 0;
}
