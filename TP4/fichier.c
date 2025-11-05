#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

void lire_fichier(const char *nom_de_fichier) {
    FILE *fichier = fopen(nom_de_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s pour lecture.\n", nom_de_fichier);
        return;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);
    char caractere;
    while ((caractere = fgetc(fichier)) != EOF) {
        putchar(caractere);
    }
    printf("\n");
    fclose(fichier);
}

void ecrire_dans_fichier(const char *nom_de_fichier, const char *message) {
    FILE *fichier = fopen(nom_de_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s pour écriture.\n", nom_de_fichier);
        return;
    }

    fprintf(fichier, "%s", message);
    fclose(fichier);
    printf("Le message a été écrit dans le fichier %s.\n", nom_de_fichier);
}
