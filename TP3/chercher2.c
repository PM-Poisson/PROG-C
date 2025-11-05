#include <stdio.h>

// Fonction qui compare deux chaînes de caractères sans utiliser strcmp
int comparer_chaine(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0; // caractères différents
        }
        i++;
    }
    // Si les deux se terminent en même temps => chaînes identiques
    return (s1[i] == '\0' && s2[i] == '\0');
}

int main() {
    // Tableau de 10 phrases
    const char phrases[10][100] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    char recherche[100];
    int trouve = 0;

    // Demander à l'utilisateur la phrase à rechercher
    printf("Entrez la phrase a rechercher :\n");
    fgets(recherche, sizeof(recherche), stdin);

    // Supprimer le '\n' éventuel de fgets
    int i = 0;
    while (recherche[i] != '\0') {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
        i++;
    }

    // Parcourir le tableau et comparer chaque phrase
    for (int j = 0; j < 10; j++) {
        if (comparer_chaine(recherche, phrases[j])) {
            trouve = 1;
            break;
        }
    }

    // Résultat
    if (trouve) {
        printf("Phrase trouvee\n");
    } else {
        printf("Phrase non trouvee\n");
    }

    return 0;
}
