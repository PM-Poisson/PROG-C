#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void envoie_message() {
    char message[MAX_MSG];
    char reponse[MAX_MSG];
    FILE *fmsg, *frep;

    printf("Votre message (max %d caracteres) : ", MAX_MSG - 1);
    fgets(message, MAX_MSG, stdin);

    fmsg = fopen("message_client.txt", "w");
    if (!fmsg) {
        perror("Erreur d'ouverture du fichier message_client.txt");
        exit(EXIT_FAILURE);
    }
    fputs(message, fmsg);
    fclose(fmsg);

    printf("Message envoye au serveur.\nEn attente de la reponse...\n");

    while (access("reponse_serveur.txt", F_OK) != 0)
        sleep(1);

    frep = fopen("reponse_serveur.txt", "r");
    if (!frep) {
        perror("Erreur d'ouverture du fichier reponse_serveur.txt");
        exit(EXIT_FAILURE);
    }

    fgets(reponse, MAX_MSG, frep);
    fclose(frep);

    printf("Message recu du serveur : %s\n", reponse);

    remove("message_client.txt");
    remove("reponse_serveur.txt");
}

void envoie_operateur_numeros(char operateur, int a, int b) {
    char message[MAX_MSG];
    char reponse[MAX_MSG];
    FILE *fmsg, *frep;

    snprintf(message, sizeof(message), "calcule : %c %d %d\n", operateur, a, b);

    fmsg = fopen("message_client.txt", "w");
    if (!fmsg) {
        perror("Erreur d'ouverture du fichier message_client.txt");
        exit(EXIT_FAILURE);
    }
    fputs(message, fmsg);
    fclose(fmsg);

    printf("Message envoye au serveur : %s", message);
    printf("En attente de la reponse...\n");

    while (access("reponse_serveur.txt", F_OK) != 0)
        sleep(1);

    frep = fopen("reponse_serveur.txt", "r");
    if (!frep) {
        perror("Erreur d'ouverture du fichier reponse_serveur.txt");
        exit(EXIT_FAILURE);
    }

    fgets(reponse, MAX_MSG, frep);
    fclose(frep);

    printf("Resultat recu du serveur : %s\n", reponse);

    remove("message_client.txt");
    remove("reponse_serveur.txt");
}

int main() {
    int choix;
    printf("=== CLIENT ===\n");
    printf("1. Envoyer un message texte\n");
    printf("2. Effectuer un calcul\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    getchar(); // consommer le retour à la ligne

    if (choix == 1) {
        envoie_message();
    } else if (choix == 2) {
        char op;
        int a, b;
        printf("Entrez l'operation (ex: + 23 45) : ");
        scanf(" %c %d %d", &op, &a, &b);
        envoie_operateur_numeros(op, a, b);
    } else {
        printf("Choix invalide.\n");
    }

    return 0;
}
