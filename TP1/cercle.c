#include <stdio.h>
#include <math.h>  

int main() {
    double rayon;
    double aire, perimetre;
    const double PI = 3.141592653589793;

    // Valeur du rayon
    printf("Entrez le rayon du cercle : ");
    scanf("%lf", &rayon);

    // Calcul de l'aire et du périmètre
    aire = PI * rayon * rayon;         
    perimetre = 2 * PI * rayon;       

    // Affichage des résultats
    printf("Aire du cercle : %.2lf\n", aire);
    printf("Perimetre du cercle : %.2lf\n", perimetre);

    return 0;
}
