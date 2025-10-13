#include "repertoire.h"
#include <stdio.h>
#include <dirent.h>   // Pour opendir(), readdir(), closedir()
#include <stdlib.h>   // Pour exit()
#include <string.h>   // Pour strcpy(), strcat()
#include <errno.h>
#include <sys/stat.h> // Pour stat() et S_ISDIR()

// Fonction simple (non récursive) du 5.1
void lire_dossier(const char *nom_repertoire) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(nom_repertoire);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }

    printf("Contenu du répertoire '%s' :\n", nom_repertoire);

    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);
}

// Fonction récursive (5.2)
void lire_dossier_recursif(const char *nom_repertoire) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(nom_repertoire);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return; // On n'arrête pas le programme complet, juste cette branche
    }

    printf("\nRépertoire : %s\n", nom_repertoire);

    while ((ent = readdir(dir)) != NULL) {
        // Ignorer . et ..
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        // Construire le chemin complet (ex: dossier/sous_dossier/fichier)
        char chemin_complet[1024];
        snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", nom_repertoire, ent->d_name);

        // Vérifie si c’est un dossier ou un fichier
        struct stat info;
        if (stat(chemin_complet, &info) == 0) {
            if (S_ISDIR(info.st_mode)) {
                printf("[Dossier] %s\n", ent->d_name);
                // Appel récursif sur le sous-répertoire
                lire_dossier_recursif(chemin_complet);
            } else {
                printf("  [Fichier] %s\n", ent->d_name);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    lire_dossier_recursif(argv[1]);
    return 0;
}
