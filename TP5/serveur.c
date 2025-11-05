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

void recois_numeros_calcule(const char *message) {
    char op;
    int a, b;
    int resultat;
    char reponse[MAX_MSG];
    FILE *frep;

    // Format attendu : "calcule : + 23 45"
    if (sscanf(message, "calcule : %c %d %d", &op, &a, &b) != 3) {
        printf("Format de calcul invalide : %s\n", message);
        return;
    }

    switch (op) {
        case '+': resultat = a + b; break;
        case '-': resultat = a - b; break;
        case '*': resultat = a * b; break;
        case '/': resultat = (b != 0) ? a / b : 0; break;
        case '%': resultat = (b != 0) ? a % b : 0; break;
        default:
            printf("Operateur non reconnu : %c\n", op);
            return;
    }

    snprintf(reponse, sizeof(reponse), "calcule : %d\n", resultat);

    frep = fopen("reponse_serveur.txt", "w");
    if (!frep) {
        perror("Erreur d'ouverture du fichier reponse_serveur.txt");
        exit(EXIT_FAILURE);
    }
    fputs(reponse, frep);
    fclose(frep);

    printf("Calcul effectue : %d %c %d = %d\n", a, op, b, resultat);
}

void recois_envoie_message() {
    char message[MAX_MSG];
    char reponse[MAX_MSG];
    FILE *fmsg, *frep;

    signal(SIGINT, quitter);
    printf("Serveur en attente de messages...\n");

    while (1) {
        while (access("message_client.txt", F_OK) != 0)
            sleep(1);

        fmsg = fopen("message_client.txt", "r");
        if (!fmsg) {
            perror("Erreur d'ouverture de message_client.txt");
            continue;
        }
        fgets(message, MAX_MSG, fmsg);
        fclose(fmsg);

        printf("Message recu : %s\n", message);

        if (strncmp(message, "calcule :", 9) == 0) {
            recois_numeros_calcule(message);
        } else {
            printf("Entrez un message a renvoyer au client : ");
            fgets(reponse, MAX_MSG, stdin);

            frep = fopen("reponse_serveur.txt", "w");
            if (!frep) {
                perror("Erreur d'ouverture du fichier reponse_serveur.txt");
                continue;
            }
            fputs(reponse, frep);
            fclose(frep);
        }

        remove("message_client.txt");
        printf("Reponse envoyee au client.\n\n");
    }
}

int main() {
    recois_envoie_message();
    return 0;
}
