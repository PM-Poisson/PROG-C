#include <stdio.h>
#include "operator.h"

// 🔹 Prototype des fonctions pour chaque exercice
void exercice_4_1();
void exercice_4_2();
void exercice_4_7();

int main() {
    int choix;

    printf("=== Programme multi-exercices ===\n");
    printf("1. Exercice 4.1 : Calcul avec operateurs\n");
    printf("2. Exercice 4.2 : (a definir)\n");
    printf("3. Exercice 4.7 : (a definir)\n");
    printf("Choisissez un exercice (1-3) : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            exercice_4_1();
            break;
        case 2:
            exercice_4_2();
            break;
        case 3:
            exercice_4_7();
            break;
        default:
            printf("Choix invalide.\n");
    }

    return 0;
}

// ================================================
// 🔹 Exercice 4.1 : Calcul avec operateurs
// ================================================
void exercice_4_1() {
    int num1, num2;
    char op;

    printf("Entrez num1 : ");
    scanf("%d", &num1);
    printf("Entrez num2 : ");
    scanf("%d", &num2);
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op); // espace avant %c pour ignorer les retours à la ligne

    int resultat = 0;
    int valid = 1;

    switch (op) {
        case '+': resultat = somme(num1, num2); break;
        case '-': resultat = difference(num1, num2); break;
        case '*': resultat = produit(num1, num2); break;
        case '/': resultat = quotient(num1, num2); break;
        case '%': resultat = modulo(num1, num2); break;
        case '&': resultat = et_logique(num1, num2); break;
        case '|': resultat = ou_logique(num1, num2); break;
        case '~': resultat = negation(num1); break; // un seul opérande
        default:
            printf("Operateur non reconnu.\n");
            valid = 0;
    }

    if (valid)
        printf("Resultat : %d\n", resultat);
}

// ================================================
// 🔹 Exercice 4.2 : à compléter plus tard
// ================================================
void exercice_4_2() {
    printf("[Exercice 4.2] Fonction non encore implementee.\n");
}

// ================================================
// 🔹 Exercice 4.7 : à compléter plus tard
// ================================================
void exercice_4_7() {
    printf("[Exercice 4.7] Fonction non encore implementee.\n");
}
