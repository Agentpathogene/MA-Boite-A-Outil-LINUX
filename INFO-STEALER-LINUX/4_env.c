#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "2_header.h"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define RESET       "\033[0m"
int am_i_root(void)
{

    int value = getuid();
    
    return value;
}

int am_i_in_graphique_session()
{

    //IL FAUDRA TESTER EN ENVIRONNEMENT CLI ET LA OU CES VAR == NULL
    char *p1 = getenv("XDG_CURRENT_DESKTOP");
    char *p2 = getenv("DISPLAY");
    char *p3 = getenv("XDG_SESSION_TYPE");//peu = tty dans cli
    char *p4 = getenv("DESKTOP_SESSION");
    char *p5 = getenv("XDG_SESSION_DESKTOP");
    int sensor1 = 0,sensor2 = 0,sensor3 = 0,sensor4 = 0,sensor5 = 0;
    

    if (!p1)
    {
        sensor1 = 0;
    }
    else
    {
        int longeur = strlen(p1);
        printf("" BLUE "Detected Content For :  " RESET ""YELLOW"XDG_CURRENT_DESKTOP" RESET " " BLUE ": Longeur = " RESET ""RED"%d" RESET "\n",longeur);
        printf("" BLUE "Detected Content For :  " RESET ""YELLOW"XDG_CURRENT_DESKTOP" RESET " " BLUE ": Content  = " RESET ""RED"%s" RESET "\n\n",p1);
        sensor1 = 1;
    }

    if (!p2)
    {
        sensor2 = 0;
    }
    else
    {
        int longeur = strlen(p2);
        printf("" BLUE "Detected Content For :" RESET ""YELLOW"DISPLAY" RESET "  " BLUE ": Longeur = " RESET ""RED"%d" RESET "\n",longeur);
        printf("" BLUE "Detected Content For :  " RESET ""YELLOW"DISPLAY" RESET " " BLUE ": Content  = " RESET ""RED"%s" RESET "\n\n",p2);
        sensor2 = 1; 
    }

    if (!p3 || strcmp(p3 ,"tty") == 0)
    {
        sensor3 = 0;
    }
    else
    {
        int longeur = strlen(p3);
        printf("" BLUE "Detected Content For :  " RESET ""YELLOW"XDG_SESSION_TYPE" RESET " " BLUE ": Longeur = " RESET ""RED"%d" RESET "\n",longeur);
        printf("" BLUE "Detected Content For :  " RESET ""YELLOW"XDG_SESSION_TYPE" RESET " " BLUE ": Content  = " RESET ""RED"%s" RESET "\n\n",p3);
        sensor3 = 1; 
    }

    if (!p4)
    {
        sensor4 = 0;
    }
    else
    {
        int longeur = strlen(p4);
        printf("" BLUE "Detected Content For : " RESET ""YELLOW"DESKTOP_SESSION" RESET "  " BLUE ": Longeur = " RESET ""RED"%d" RESET "\n",longeur);
        printf("" BLUE "Detected Content For :  " RESET ""YELLOW"DESKTOP_SESSION" RESET " " BLUE ": Content  = " RESET ""RED"%s" RESET "\n\n",p4);
        sensor4 = 1; 
    }

    if (!p5)
    {
        sensor5 = 0;
    }
    else
    {
        int longeur = strlen(p5);
        printf("" BLUE "Detected Content For : " RESET ""YELLOW"XDG_SESSION_DESKTOP" RESET "  " BLUE ": Longeur = " RESET ""RED"%d" RESET "\n",longeur);
        printf("" BLUE "Detected Content For :  " RESET ""YELLOW"XDG_SESSION_DESKTOP" RESET " " BLUE ": Content  = " RESET ""RED"%s" RESET "\n\n",p5);
        sensor5 = 1; 
    }

    if (sensor1 + sensor2 + sensor3 + sensor4 + sensor5 != 0)
    {
        printf(""MAGENTA"GRAPHIQUE SESSION DETECTED"RESET"\n\n");
        pid_t pidparent = getpid();
        printf(""CYAN"PID du Processus en cours : "RESET""RED"%d"RESET"\n\n",pidparent);
        popup_root();

    }
    else
    {
        printf(""YELLOW"NO GRAPHICAL INTERFACE DETECTED CONTINUE WITHOU POP UP\n"RESET"");
        privesc_faille_rec();

    }


    return 0;
}