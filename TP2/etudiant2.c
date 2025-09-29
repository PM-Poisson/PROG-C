#include <stdio.h>
#include <string.h>

#define N 5   // nombre d'étudiants

// Définition de la structure pour stocker les informations d'un étudiant
struct Etudiant {
    char nom[30];
    char prenom[30];
    char adresse[100];
    float note_prog;
    float note_sys;
};

int main() {
    struct Etudiant etudiants[N];

    // Saisie des informations
    for (int i = 0; i < N; i++) {
        printf("\n=== Etudiant %d ===\n", i + 1);

        printf("Nom : ");
        scanf("%29s", etudiants[i].nom);

        printf("Prenom : ");
        scanf("%29s", etudiants[i].prenom);

        printf("Adresse : ");
        getchar(); // pour consommer le \n restant
        fgets(etudiants[i].adresse, 100, stdin);
        // Retirer le \n à la fin de fgets si présent
        etudiants[i].adresse[strcspn(etudiants[i].adresse, "\n")] = '\0';

        printf("Note Programmation en C : ");
        scanf("%f", &etudiants[i].note_prog);

        printf("Note Systeme d'exploitation : ");
        scanf("%f", &etudiants[i].note_sys);
    }

    // Affichage des informations
    printf("\n===== Liste des Etudiants =====\n");
    for (int i = 0; i < N; i++) {
        printf("\nEtudiant %d :\n", i + 1);
        printf("Nom       : %s\n", etudiants[i].nom);
        printf("Prenom    : %s\n", etudiants[i].prenom);
        printf("Adresse   : %s\n", etudiants[i].adresse);
        printf("Note Prog : %.2f\n", etudiants[i].note_prog);
        printf("Note Sys  : %.2f\n", etudiants[i].note_sys);
    }

    return 0;
}
