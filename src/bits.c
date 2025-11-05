#include <stdio.h>

int main() {
    unsigned int d = 0x10001000; // exemple de valeur en hexadécimal
    int taille = sizeof(d) * 8;  // nombre total de bits (souvent 32 en C)

    // Position des bits depuis la gauche
    int pos4  = taille - 4;   // 4ème bit de gauche
    int pos20 = taille - 20;  // 20ème bit de gauche

    // Vérification des bits avec masquage
    int bit4  = (d >> pos4) & 1;
    int bit20 = (d >> pos20) & 1;

    // Résultat
    if (bit4 == 1 && bit20 == 1)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
