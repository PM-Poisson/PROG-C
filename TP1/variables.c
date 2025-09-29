#include <stdio.h>

int main() {
    // Déclaration des variables
    char c;
    signed char sc;
    unsigned char uc;

    short s;
    unsigned short us;

    int i;
    unsigned int ui;

    long int li;
    unsigned long int uli;

    long long int lli;
    unsigned long long int ulli;

    float f;
    double d;
    long double ld;

    // Saisie utilisateur avec exemples
    printf("Entrez un char (exemple : A) : ");
    scanf(" %c", &c);

    printf("Entrez un signed char (exemple : -100) : ");
    scanf("%hhd", &sc);

    printf("Entrez un unsigned char (exemple : 200) : ");
    scanf("%hhu", &uc);

    printf("Entrez un short (exemple : -30000) : ");
    scanf("%hd", &s);

    printf("Entrez un unsigned short (exemple : 60000) : ");
    scanf("%hu", &us);

    printf("Entrez un int (exemple : -100000) : ");
    scanf("%d", &i);

    printf("Entrez un unsigned int (exemple : 300000) : ");
    scanf("%u", &ui);

    printf("Entrez un long int (exemple : -1000000000) : ");
    scanf("%ld", &li);

    printf("Entrez un unsigned long int (exemple : 3000000000) : ");
    scanf("%lu", &uli);

    printf("Entrez un long long int (exemple : -5000000000) : ");
    scanf("%lld", &lli);

    printf("Entrez un unsigned long long int (exemple : 10000000000) : ");
    scanf("%llu", &ulli);

    printf("Entrez un float (exemple : 3.14) : ");
    scanf("%f", &f);

    printf("Entrez un double (exemple : 3.1415926535) : ");
    scanf("%lf", &d);

    printf("Entrez un long double (exemple : 3.141592653589793238) : ");
    scanf("%Lf", &ld);

    // Affichage des valeurs
    printf("\nValeurs saisies :\n\n");

    printf("char : %c\n", c);
    printf("signed char : %d\n", sc);
    printf("unsigned char : %u\n\n", uc);

    printf("short : %d\n", s);
    printf("unsigned short : %u\n\n", us);

    printf("int : %d\n", i);
    printf("unsigned int : %u\n\n", ui);

    printf("long int : %ld\n", li);
    printf("unsigned long int : %lu\n\n", uli);

    printf("long long int : %lld\n", lli);
    printf("unsigned long long int : %llu\n\n", ulli);

    printf("float : %.2f\n", f);
    printf("double : %.10lf\n", d);
    printf("long double : %.18Lf\n", ld);

    return 0;
}
