#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// === Exercice 4.1 ===
// Calcul avec opérateurs
void exercice_4_1() {
    int num1, num2, resultat;
    char op;

    printf("=== Exercice 4.1 : Calcul avec opérateurs ===\n");
    printf("Entrez num1 : ");
    scanf("%d", &num1);
    printf("Entrez num2 : ");
    scanf("%d", &num2);
    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            resultat = somme(num1, num2);
            break;
        case '-':
            resultat = difference(num1, num2);
            break;
        case '*':
            resultat = produit(num1, num2);
            break;
        case '/':
            resultat = quotient(num1, num2);
            break;
        case '%':
            resultat = modulo(num1, num2);
            break;
        case '&':
            resultat = et(num1, num2);
            break;
        case '|':
            resultat = ou(num1, num2);
            break;
        case '~':
            resultat = negation(num1);
            break;
        default:
            printf("Opérateur invalide.\n");
            return;
    }

    printf("Résultat : %d\n", resultat);
}

// === Exercice 4.2 ===
// Gestion de fichiers
void exercice_4_2() {
    int choix;
    char nom_de_fichier[100];
    char message[256];

    printf("=== Exercice 4.2 : Gestion de fichiers ===\n");
    printf("Que souhaitez-vous faire ?\n");
    printf("1. Lire un fichier\n");
    printf("2. Écrire dans un fichier\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    getchar(); // consomme le \n restant

    switch (choix) {
        case 1:
            printf("Entrez le nom du fichier à lire : ");
            fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin);
            nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0';
            lire_fichier(nom_de_fichier);
            break;

        case 2:
            printf("Entrez le nom du fichier dans lequel écrire : ");
            fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin);
            nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0';

            printf("Entrez le message à écrire : ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';

            ecrire_dans_fichier(nom_de_fichier, message);
            break;

        default:
            printf("Choix invalide.\n");
            break;
    }
}

// === Exercice 4.7 ===
// Gestion d'une liste de couleurs
void exercice_4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);

    printf("=== Exercice 4.7 : Gestion d'une liste de couleurs ===\n");

    // Création de 10 couleurs (format RGBA)
    struct couleur couleurs[10] = {
        {0xFF, 0x00, 0x00, 0xFF}, // rouge
        {0x00, 0xFF, 0x00, 0xFF}, // vert
        {0x00, 0x00, 0xFF, 0xFF}, // bleu
        {0xFF, 0xFF, 0x00, 0xFF}, // jaune
        {0x00, 0xFF, 0xFF, 0xFF}, // cyan
        {0xFF, 0x00, 0xFF, 0xFF}, // magenta
        {0x80, 0x80, 0x80, 0xFF}, // gris
        {0xFF, 0xA5, 0x00, 0xFF}, // orange
        {0x8B, 0x00, 0x8B, 0xFF}, // violet
        {0x00, 0x00, 0x00, 0xFF}  // noir
    };

    // Insertion des couleurs dans la liste
    for (int i = 0; i < 10; i++) {
        insertion(&couleurs[i], &ma_liste);
    }

    // Affichage des couleurs
    printf("\nListe des couleurs :\n");
    parcours(&ma_liste);
}

// === Fonction principale ===
int main() {
    int choix;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Exercice 4.1 - Calcul avec opérateurs\n");
        printf("2. Exercice 4.2 - Gestion de fichiers\n");
        printf("3. Exercice 4.7 - Liste de couleurs\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                exercice_4_1();
                break;
            case 2:
                exercice_4_2();
                break;
            case 3:
                exercice_4_7();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
