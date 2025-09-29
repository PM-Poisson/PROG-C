#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

// Définition d'une couleur RGBA
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Couleur;

// Structure pour stocker une couleur distincte + son nombre d'occurrences
typedef struct {
    Couleur c;
    int occurrences;
} CouleurComptee;

// Fonction de comparaison entre deux couleurs
int comparer_couleurs(Couleur c1, Couleur c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

// Fonction pour afficher une couleur
void afficher_couleur(Couleur c) {
    printf("0x%02x 0x%02x 0x%02x 0x%02x", c.r, c.g, c.b, c.a);
}

int main() {
    Couleur couleurs[N];
    CouleurComptee distinctes[N];
    int nb_distinctes = 0;

    srand(time(NULL));

    // Remplissage du tableau avec des couleurs aléatoires
    for (int i = 0; i < N; i++) {
        couleurs[i].r = rand() % 256;
        couleurs[i].g = rand() % 256;
        couleurs[i].b = rand() % 256;
        couleurs[i].a = 0xff; // alpha fixé à 255
    }

    // Comptage des couleurs distinctes
    for (int i = 0; i < N; i++) {
        int trouve = 0;
        for (int j = 0; j < nb_distinctes; j++) {
            if (comparer_couleurs(couleurs[i], distinctes[j].c)) {
                distinctes[j].occurrences++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            distinctes[nb_distinctes].c = couleurs[i];
            distinctes[nb_distinctes].occurrences = 1;
            nb_distinctes++;
        }
    }

    // Affichage des couleurs distinctes et de leurs occurrences
    printf("Couleurs distinctes et occurrences :\n");
    for (int i = 0; i < nb_distinctes; i++) {
        afficher_couleur(distinctes[i].c);
        printf(" : %d\n", distinctes[i].occurrences);
    }

    return 0;
}
