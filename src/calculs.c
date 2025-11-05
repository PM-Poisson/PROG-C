#include <stdio.h>

int main() {
    int num1, num2;
    char op;

    // Saisie des valeurs
    printf("Entrez le premier entier : ");
    scanf("%d", &num1);

    printf("Entrez le second entier : ");
    scanf("%d", &num2);

    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);  // espace avant %c pour ignorer le retour à la ligne

    switch(op) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            else
                printf("Erreur : division par zero !\n");
            break;
        case '%':
            if (num2 != 0)
                printf("%d %% %d = %d\n", num1, num2, num1 % num2);
            else
                printf("Erreur : modulo par zero !\n");
            break;
        case '&':
            printf("%d & %d = %d\n", num1, num2, num1 & num2);
            break;
        case '|':
            printf("%d | %d = %d\n", num1, num2, num1 | num2);
            break;
        case '~':
            // Opérateur NOT (~) s'applique à un seul nombre : on applique à num1
            printf("~%d = %d\n", num1, ~num1);
            break;
        default:
            printf("Operateur inconnu !\n");
    }

    return 0;
}
