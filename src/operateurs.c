#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    // Opérateurs arithmétiques
    printf("a = %d, b = %d\n\n", a, b);
    printf("Addition (a + b) : %d\n", a + b);
    printf("Soustraction (a - b) : %d\n", a - b);
    printf("Multiplication (a * b) : %d\n", a * b);
    printf("Division (a / b) : %d\n", a / b);
    printf("Modulo (a %% b) : %d\n\n", a % b); // %% pour afficher le symbole %

    // Opérateurs de comparaison (résultat : 1 = vrai, 0 = faux)
    printf("a == b : %d\n", a == b);
    printf("a > b  : %d\n", a > b);

    return 0;
}
