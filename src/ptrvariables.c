#include <stdio.h>

int main() {
    // Déclaration des variables de base
    char c = 'A';
    short s = 1234;
    int i = 56789;
    long int li = 1234567;
    long long int lli = 9876543210;
    float f = 3.14f;
    double d = 2.718281828;
    long double ld = 1.6180339887L;

    // Pointeurs vers les variables
    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pli = &li;
    long long int *plli = &lli;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    printf("=== Avant manipulation ===\n");
    printf("Adresse de c  : %p, Valeur : %c (0x%X)\n", (void*)pc, *pc, *pc);
    printf("Adresse de s  : %p, Valeur : %d (0x%hX)\n", (void*)ps, *ps, *ps);
    printf("Adresse de i  : %p, Valeur : %d (0x%X)\n", (void*)pi, *pi, *pi);
    printf("Adresse de li : %p, Valeur : %ld (0x%lX)\n", (void*)pli, *pli, *pli);
    printf("Adresse de lli: %p, Valeur : %lld (0x%llX)\n", (void*)plli, *plli, *plli);
    printf("Adresse de f  : %p, Valeur : %f\n", (void*)pf, *pf);
    printf("Adresse de d  : %p, Valeur : %f\n", (void*)pd, *pd);
    printf("Adresse de ld : %p, Valeur : %Lf\n", (void*)pld, *pld);

    // --- Manipulation via pointeurs ---
    *pc = 'B';
    *ps += 1;
    *pi -= 1;
    *pli += 10;
    *plli -= 1000;
    *pf *= 2.0f;
    *pd /= 2.0;
    *pld += 0.5L;

    printf("\n=== Apres manipulation ===\n");
    printf("Adresse de c  : %p, Valeur : %c (0x%X)\n", (void*)pc, *pc, *pc);
    printf("Adresse de s  : %p, Valeur : %d (0x%hX)\n", (void*)ps, *ps, *ps);
    printf("Adresse de i  : %p, Valeur : %d (0x%X)\n", (void*)pi, *pi, *pi);
    printf("Adresse de li : %p, Valeur : %ld (0x%lX)\n", (void*)pli, *pli, *pli);
    printf("Adresse de lli: %p, Valeur : %lld (0x%llX)\n", (void*)plli, *plli, *plli);
    printf("Adresse de f  : %p, Valeur : %f\n", (void*)pf, *pf);
    printf("Adresse de d  : %p, Valeur : %f\n", (void*)pd, *pd);
    printf("Adresse de ld : %p, Valeur : %Lf\n", (void*)pld, *pld);

    return 0;
}
