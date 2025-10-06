#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"   // Pour réutiliser ecrire_dans_fichier()

#define NB_ETUDIANTS 5

// Définition de la structure Étudiant
typedef struct {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float note1;
    float note2;
} Etudiant;

int main() {
    Etudiant etudiants[NB_ETUDIANTS];
    char ligne[512];
    const char *nom_fichier = "etudiant.txt";

    printf("=== Exercice 4.3 : Gestion d'une base de données étudiante ===\n\n");

    // Saisie des informations pour chaque étudiant
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Entrez les détails de l'étudiant.e %d :\n", i + 1);
        printf("Nom : ");
        scanf(" %[^\n]", etudiants[i].nom);
        printf("Prénom : ");
        scanf(" %[^\n]", etudiants[i].prenom);
        printf("Adresse : ");
        scanf(" %[^\n]", etudiants[i].adresse);
        printf("Note 1 : ");
        scanf("%f", &etudiants[i].note1);
        printf("Note 2 : ");
        scanf("%f", &etudiants[i].note2);
        printf("\n");
    }

    // Écriture dans le fichier
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NB_ETUDIANTS; i++) {
        fprintf(fichier, "%s;%s;%s;%.2f;%.2f\n",
                etudiants[i].nom,
                etudiants[i].prenom,
                etudiants[i].adresse,
                etudiants[i].note1,
                etudiants[i].note2);
    }

    fclose(fichier);

    printf("✅ Les détails des étudiants ont été enregistrés dans '%s'.\n", nom_fichier);

    return 0;
}
