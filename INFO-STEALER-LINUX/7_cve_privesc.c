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

int copy_fail(void)
{
    printf("\n\nTu fais du reverse sur mon malware ? allez courage je m'apelle agentpathogene ravi de te rencontrer\n");
    printf("         "CYAN"_nnnn_"RESET"      "MAGENTA"*"RESET"\n");
    printf("        "CYAN"dGGGGMMb"RESET"   "MAGENTA"*"RESET"        "MAGENTA"*"RESET"\n");
    printf("       "CYAN"@p~qp~~qMb"RESET"        "MAGENTA"*"RESET"   "MAGENTA"*"RESET"\n");
    printf("       "CYAN"M|"RESET""YELLOW"@"RESET""CYAN"||"RESET""YELLOW"@"RESET""CYAN") M|"RESET"\n");
    printf("       "CYAN"@,----"CYAN".JM|"RESET" \n");
    printf("       "CYAN"JS^"RESET"__/  "CYAN"qKL"RESET"     "MAGENTA"*"RESET"\n");
    printf("      "CYAN"dZP        qKRb"RESET"      "MAGENTA"*"RESET" \n");
    printf("     "CYAN"nFS          qKKb"RESET" \n");
    printf("    "CYAN"fTP            SMMb"RESET"\n");
    printf("    "CYAN"HZM            MMMM"RESET"\n");
    printf("    "CYAN"FqM            MMMM"RESET"\n");
    printf("  __"YELLOW"| '.        |"RESET""CYAN"dS'qML"RESET"\n");
    printf(" "YELLOW"|    `.       | `' -"RESET""CYAN"Zq"RESET"\n");
    printf(" "YELLOW")      '"RESET""CYAN".___.,"RESET""YELLOW"|     .'"RESET"\n");
    printf(""YELLOW" ___   )"RESET""CYAN"MMMMMM"RESET""YELLOW"|   .'"RESET"\n");
    printf("      "YELLOW"`-'       `--'"RESET"\n");

    printf("Y aurait pu avoir payload pour copy fail mais c'est surtout un info stealer\n");
    printf("Ce programme a pour but de montrer qu'il est facil de creer des malware de base\n");
    printf("cree un malware avance est une autre histoire...");








    return 0;
}