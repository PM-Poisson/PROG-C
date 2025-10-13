#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void envoie_message() {
    char message[MAX_MSG];
    char reponse[MAX_MSG];
    FILE *fmsg, *frep;

    printf("Votre message (max %d caractères) : ", MAX_MSG - 1);
    fgets(message, MAX_MSG, stdin);

    // Écriture du message dans un fichier partagé
    fmsg = fopen("message_client.txt", "w");
    if (!fmsg) {
        perror("Erreur d'ouverture du fichier message_client.txt");
        exit(EXIT_FAILURE);
    }
    fputs(message, fmsg);
    fclose(fmsg);

    printf("Message envoyé au serveur.\nEn attente de la réponse...\n");

    // Attente de la réponse (jusqu'à ce que le fichier soit créé)
    while (access("reponse_serveur.txt", F_OK) != 0) {
        sleep(1);
    }

    frep = fopen("reponse_serveur.txt", "r");
    if (!frep) {
        perror("Erreur de lecture du fichier reponse_serveur.txt");
        exit(EXIT_FAILURE);
    }

    fgets(reponse, MAX_MSG, frep);
    fclose(frep);

    printf("Message reçu du serveur : %s\n", reponse);

    // Suppression des fichiers après lecture
    remove("message_client.txt");
    remove("reponse_serveur.txt");
}

int main() {
    envoie_message();
    return 0;
}
