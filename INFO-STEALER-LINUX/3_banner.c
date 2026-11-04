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

int banner(void)
{
printf("\n,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");
printf("| " MAGENTA "~" RESET " | " CYAN "1" RESET " | " CYAN "2" RESET " | " CYAN "3" RESET " | " CYAN "4" RESET " | " CYAN "5" RESET " | " CYAN "6" RESET " | " CYAN "7" RESET " | " CYAN "8" RESET " | " CYAN "9" RESET " | " CYAN "0" RESET " | " MAGENTA "[" RESET " | " MAGENTA "]" RESET " | " WHITE "<-" RESET "    |\n");
printf("|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|\n");
printf("| " WHITE "->|" RESET " | " MAGENTA "*" RESET " | " MAGENTA "," RESET " | " MAGENTA "." RESET " | " YELLOW "P" RESET " | " YELLOW "Y" RESET " | " YELLOW "F" RESET " | " YELLOW "G" RESET " | " YELLOW "C" RESET " | " YELLOW "R" RESET " | " YELLOW "L" RESET " | " MAGENTA "/" RESET " | " MAGENTA "=" RESET " |  " WHITE "/" RESET "  |\n");
printf("|-----',--',--',--',--',--',--',--',--',--',--',--',--'-----|\n");
printf("| " WHITE "Caps" RESET " | " GREEN "A" RESET " | " GREEN "G" RESET " | " GREEN "E" RESET " | " GREEN "N" RESET " | " GREEN "T" RESET " | " GREEN "P" RESET " | " GREEN "A" RESET " | " GREEN "T" RESET " | " GREEN "H" RESET " | " GREEN "O" RESET " | " MAGENTA "-" RESET " |  " WHITE "Enter" RESET " |\n");
printf("|------'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'--------|\n");
printf("|        | " MAGENTA ";" RESET " | " GREEN "G" RESET " | " GREEN "E" RESET " | " GREEN "N" RESET " | " GREEN "E" RESET " | " RED "X" RESET " | " RED "X" RESET " | " RED "X" RESET " | " RED "X" RESET " | " RED "X" RESET " |          |\n");
printf("|------,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|\n");
printf("| " WHITE "ctrl" RESET " |  | " BLUE "alt" RESET " |                          | " BLUE "alt" RESET "  |  | " WHITE "ctrl" RESET " |\n");
printf("'------'  '-----'--------------------------'------'  '------'\n\n");

    return 0;
}