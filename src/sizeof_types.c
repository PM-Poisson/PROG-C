#include <stdio.h>

int main() {
    printf("Taille des types de base en C :\n\n");

    // Types entiers
    printf("char : %zu octets\n", sizeof(char));
    printf("signed char : %zu octets\n", sizeof(signed char));
    printf("unsigned char : %zu octets\n\n", sizeof(unsigned char));

    printf("short : %zu octets\n", sizeof(short));
    printf("unsigned short : %zu octets\n\n", sizeof(unsigned short));

    printf("int : %zu octets\n", sizeof(int));
    printf("unsigned int : %zu octets\n\n", sizeof(unsigned int));

    printf("long int : %zu octets\n", sizeof(long int));
    printf("unsigned long int : %zu octets\n\n", sizeof(unsigned long int));

    printf("long long int : %zu octets\n", sizeof(long long int));
    printf("unsigned long long int : %zu octets\n\n", sizeof(unsigned long long int));

    // Types flottants
    printf("float : %zu octets\n", sizeof(float));
    printf("double : %zu octets\n", sizeof(double));
    printf("long double : %zu octets\n", sizeof(long double));

    return 0;
}
