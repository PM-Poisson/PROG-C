#include <stdio.h>

void afficher_octets(void *ptr, size_t taille) {
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < taille; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

int main() {
    short s = 0x0302;          // valeur choisie pour voir les octets
    int i = 0x04030201;
    long int li = 0x0807060504030201;
    float f = 4.25f;           // exemple valeur float
    double d = 3.141592653589793;
    long double ld = 2.718281828459045L;

    printf("Octets de short :\n");
    afficher_octets(&s, sizeof(short));

    printf("\nOctets de int :\n");
    afficher_octets(&i, sizeof(int));

    printf("\nOctets de long int :\n");
    afficher_octets(&li, sizeof(long int));

    printf("\nOctets de float :\n");
    afficher_octets(&f, sizeof(float));

    printf("\nOctets de double :\n");
    afficher_octets(&d, sizeof(double));

    printf("\nOctets de long double :\n");
    afficher_octets(&ld, sizeof(long double));

    return 0;
}
