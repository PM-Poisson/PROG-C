#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour compter le nombre d'occurrences d'une sous-chaîne dans une chaîne
int compter_occurrences(const char *ligne, const char *phrase) {
    int count = 0;
    const char *ptr = ligne;

    while ((ptr = strstr(ptr, phrase)) != NULL) {
        count++;
        ptr += strlen(phrase); // avancer après la dernière occurrence trouvée
    }

    return count;
}

int main() {
    char nom_fichier[100];
    char phrase[200];
    char ligne[512];
    FILE *fichier;
    int num_ligne = 0;
    int total_trouvees = 0;

    printf("=== Recherche de phrases dans un fichier ===\n");

    // Demande du nom du fichier
    printf("Entrez le nom du fichier : ");
    scanf("%99s", nom_fichier);

    // Vider le tampon d'entrée avant fgets()
    getchar();

    // Demande de la phrase à rechercher
    printf("Entrez la phrase que vous souhaitez rechercher : ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0'; // suppression du saut de ligne

    // Ouverture du fichier
    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    printf("\nRésultats de la recherche :\n");

    // Lecture du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        num_ligne++;
        int nb_occurrences = compter_occurrences(ligne, phrase);
        if (nb_occurrences > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, nb_occurrences);
            total_trouvees += nb_occurrences;
        }
    }

    if (total_trouvees == 0) {
        printf("La phrase \"%s\" n'a pas été trouvée dans le fichier.\n", phrase);
    }

    fclose(fichier);
    return 0;
}
