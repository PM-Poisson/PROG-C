#include <stdio.h>

int main() {
    // Tableaux pour stocker les informations
    char noms[5][30] = {"Dupont", "Martin", "Durand", "Bernard", "Petit"};
    char prenoms[5][30] = {"Alice", "Bob", "Claire", "David", "Emma"};
    char adresses[5][100] = {
        "10 rue de Paris",
        "25 avenue de Lyon",
        "5 boulevard Victor Hugo",
        "42 rue Nationale",
        "7 impasse des Lilas"
    };

    float notesProgC[5] = {15.5, 12.0, 18.0, 10.5, 14.0};
    float notesSys[5] = {13.0, 16.5, 11.5, 17.0, 15.0};

    // Affichage des informations
    printf("===== Liste des etudiants =====\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom       : %s\n", noms[i]);
        printf("Prenom    : %s\n", prenoms[i]);
        printf("Adresse   : %s\n", adresses[i]);
        printf("Note Prog : %.2f\n", notesProgC[i]);
        printf("Note Sys  : %.2f\n", notesSys[i]);
        printf("---------------------------\n");
    }

    return 0;
}
