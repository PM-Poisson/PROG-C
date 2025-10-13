#include "repertoire.h"
#include <stdio.h>
#include <dirent.h>   // Pour opendir(), readdir(), closedir()
#include <stdlib.h>   // Pour exit()
#include <errno.h>    // Pour gérer les erreurs

void lire_dossier(const char *nom_repertoire) {
    DIR *dir;
    struct dirent *ent;

    // Ouvre le répertoire
    dir = opendir(nom_repertoire);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }

    printf("Contenu du répertoire '%s' :\n", nom_repertoire);

    // Parcourt les fichiers et dossiers
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    // Ferme le répertoire
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    lire_dossier(argv[1]);
    return 0;
}
