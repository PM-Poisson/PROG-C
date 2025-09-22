#include <stdio.h>

// Fonction pour calculer la longueur d'une chaîne
int longueur(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fonction pour copier une chaîne
void copier(const char *source, char *destination) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // ajouter le caractère de fin
}

// Fonction pour concaténer deux chaînes
void concatener(char *destination, const char *source) {
    int i = 0;
    int j = 0;

    // Aller jusqu'à la fin de destination
    while (destination[i] != '\0') {
        i++;
    }

    // Copier source à la suite
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = '\0'; // terminer la chaîne
}

int main() {
    char chaine1[50] = "Hello";
    char chaine2[50] = " World !";
    char copie[50];

    // Longueur
    printf("Longueur de chaine1 = %d\n", longueur(chaine1));

    // Copie
    copier(chaine1, copie);
    printf("Copie de chaine1 = %s\n", copie);

    // Concaténation
    concatener(chaine1, chaine2);
    printf("Concatenation = %s\n", chaine1);

    return 0;
}
