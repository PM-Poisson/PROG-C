#include "repertoire.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

// Déclaration de constantes pour la pile
#define MAX_PATH 1024
#define MAX_STACK_SIZE 512

// Version itérative : parcours de tous les sous-répertoires sans récursion
void lire_dossier_iteratif(const char *nom_repertoire) {
    // Tableau qui servira de pile pour stocker les chemins à explorer
    char pile[MAX_STACK_SIZE][MAX_PATH];
    int sommet = 0;  // Index du sommet de la pile

    // On commence avec le dossier de départ
    strncpy(pile[sommet++], nom_repertoire, MAX_PATH - 1);

    // Tant qu'il reste des dossiers à parcourir
    while (sommet > 0) {
        // On retire un répertoire de la pile
        char dossier_courant[MAX_PATH];
        strncpy(dossier_courant, pile[--sommet], MAX_PATH - 1);

        DIR *dir = opendir(dossier_courant);
        if (dir == NULL) {
            perror("Erreur lors de l'ouverture du répertoire");
            continue;
        }

        printf("\nRépertoire : %s\n", dossier_courant);

        struct dirent *ent;
        while ((ent = readdir(dir)) != NULL) {
            // Ignorer . et ..
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;

            // Créer le chemin complet
            char chemin_complet[MAX_PATH];
            snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", dossier_courant, ent->d_name);

            // Vérifier si c’est un dossier ou un fichier
            struct stat info;
            if (stat(chemin_complet, &info) == 0) {
                if (S_ISDIR(info.st_mode)) {
                    printf("[Dossier] %s\n", ent->d_name);

                    // Ajouter ce sous-répertoire à la pile
                    if (sommet < MAX_STACK_SIZE)
                        strncpy(pile[sommet++], chemin_complet, MAX_PATH - 1);
                    else
                        fprintf(stderr, "⚠️ Pile pleine, impossible d’ajouter %s\n", chemin_complet);
                } else {
                    printf("  [Fichier] %s\n", ent->d_name);
                }
            }
        }

        closedir(dir);
    }
}



int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    lire_dossier_iteratif(argv[1]);
    return 0;
}

