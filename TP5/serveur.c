#include "serveur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void quitter(int sig) {
    printf("\nSignal Ctrl+C capture. Sortie du programme.\n");
    exit(0);
}

void recois_envoie_message() {
    char message[MAX_MSG];
    char reponse[MAX_MSG];
    FILE *fmsg, *frep;

    signal(SIGINT, quitter);
    printf("Serveur en attente de messages...\n");

    while (1) {
        // Attendre que le client écrive un message
        while (access("message_client.txt", F_OK) != 0) {
            sleep(1);
        }

        // Lecture du message du client
        fmsg = fopen("message_client.txt", "r");
        if (!fmsg) {
            perror("Erreur de lecture du message_client.txt");
            continue;
        }
        fgets(message, MAX_MSG, fmsg);
        fclose(fmsg);

        printf("Message recu : %s\n", message);

        // Saisie de la réponse
        printf("Entrez un message a renvoyer au client : ");
        fgets(reponse, MAX_MSG, stdin);

        // Écriture de la réponse dans un autre fichier
        frep = fopen("reponse_serveur.txt", "w");
        if (!frep) {
            perror("Erreur d'ouverture du fichier reponse_serveur.txt");
            continue;
        }
        fputs(reponse, frep);
        fclose(frep);

        // Attente de la prochaine communication
        remove("message_client.txt");
        printf("Réponse envoyee au client.\nEn attente d'un nouveau message...\n\n");
    }
}

int main() {
    recois_envoie_message();
    return 0;
}
