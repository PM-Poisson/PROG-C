#include <stdio.h>
#include <stdlib.h>
#include "operator.h"  // Fonctions somme, difference, produit, etc.

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Utilisation : %s <opérateur> <num1> <num2>\n", argv[0]);
        printf("Exemple : %s + 10 5\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    int resultat;

    switch (op) {
        case '+':
            resultat = somme(num1, num2);
            break;
        case '-':
            resultat = difference(num1, num2);
            break;
        case '*':
            resultat = produit(num1, num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Erreur : division par zéro\n");
                return 1;
            }
            resultat = quotient(num1, num2);
            break;
        case '%':
            resultat = modulo(num1, num2);
            break;
        case '&':
            resultat = et(num1, num2);
            break;
        case '|':
            resultat = ou(num1, num2);
            break;
        case '~':
            // Négation : on applique sur num1 seulement
            resultat = negation(num1);
            break;
        default:
            printf("Erreur : opérateur '%c' non reconnu\n", op);
            return 1;
    }

    printf("Résultat : %d\n", resultat);
    return 0;
}
