#include <stdio.h>
#include <stdint.h> // pour uint8_t

// Définition d'une structure pour représenter une couleur RGBA
struct Couleur {
    uint8_t r; // Rouge (0-255)
    uint8_t g; // Vert (0-255)
    uint8_t b; // Bleu (0-255)
    uint8_t a; // Alpha (0-255, transparence)
};

int main() {
    // Tableau de 10 couleurs
    struct Couleur couleurs[10] = {
        {0xef, 0x78, 0x12, 0xff}, // Couleur 1
        {0x2c, 0xc8, 0x64, 0xff}, // Couleur 2
        {0x00, 0x00, 0xff, 0x80}, // Couleur 3
        {0xff, 0x00, 0x00, 0xff}, // Couleur 4
        {0x00, 0xff, 0x00, 0xff}, // Couleur 5
        {0xaa, 0xbb, 0xcc, 0xdd}, // Couleur 6
        {0x12, 0x34, 0x56, 0x78}, // Couleur 7
        {0x90, 0xab, 0xcd, 0xef}, // Couleur 8
        {0xff, 0xff, 0x00, 0xff}, // Couleur 9
        {0x11, 0x22, 0x33, 0x44}  // Couleur 10
    };

    // Affichage des couleurs
    for (int i = 0; i < 10; i++) {
        printf("\nCouleur %d :\n", i + 1);
        printf("Rouge : %u\n", couleurs[i].r);
        printf("Vert  : %u\n", couleurs[i].g);
        printf("Bleu  : %u\n", couleurs[i].b);
        printf("Alpha : %u\n", couleurs[i].a);
    }

    return 0;
}
