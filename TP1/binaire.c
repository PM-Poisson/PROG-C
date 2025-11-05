#include <stdio.h>

void afficherBinaire(unsigned int n) {
    int taille = sizeof(n) * 8; // nombre de bits (32 sur la plupart des systèmes)
    int debut = 0; // pour éviter d'afficher les zéros inutiles au début

    for (int i = taille - 1; i >= 0; i--) {
        unsigned int masque = 1u << i;
        if (n & masque) {
            printf("1");
            debut = 1; // on commence à afficher à partir du premier 1
        } else if (debut) {
            printf("0");
        }
    }

    if (!debut) {
        printf("0"); // si n = 0, afficher 0
    }
    printf("\n");
}

int main() {
    unsigned int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = sizeof(nombres) / sizeof(nombres[0]);

    for (int i = 0; i < taille; i++) {
        printf("%u en binaire : ", nombres[i]);
        afficherBinaire(nombres[i]);
    }

    return 0;
}
