#include <stdio.h>
#include <stdlib.h>

#define TAILLE 100

// Fonction de recherche dichotomique
int recherche_dichotomique(int tableau[], int taille, int cible) {
    int debut = 0;
    int fin = taille - 1;

    while (debut <= fin) {
        int milieu = (debut + fin) / 2;

        if (tableau[milieu] == cible) {
            return 1; // trouvé
        } else if (tableau[milieu] < cible) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }
    return 0; // non trouvé
}

int main() {
    int tableau[TAILLE];
    int i, cible;

    // Remplir le tableau avec des nombres triés (par exemple, 0 à 99 multipliés par 2)
    for (i = 0; i < TAILLE; i++) {
        tableau[i] = i * 2;  // 0, 2, 4, 6, ...
    }

    // Affichage du tableau trié
    printf("Tableau trie :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%4d ", tableau[i]);
        if ((i + 1) % 10 == 0) { // retour à la ligne tous les 10 éléments
            printf("\n");
        }
    }

    // Demander un entier à chercher
    printf("\nEntrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &cible);

    // Appel de la recherche dichotomique
    if (recherche_dichotomique(tableau, TAILLE, cible)) {
        printf("Resultat : entier present\n");
    } else {
        printf("Resultat : entier absent\n");
    }

    return 0;
}
