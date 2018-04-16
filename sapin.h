#ifndef SAPIN_H_
#define SAPIN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define RED           "\x1b[31m"
#define RED_FOND      "\x1b[41m"
#define GREEN         "\x1b[32m"
#define YELLOW_FOND   "\x1b[42m"
#define YELLOW        "\x1b[33m"
#define GREEN_FOND    "\x1b[43m"
#define BRIGHTYELLOW  "\x1b[93m"
#define BLUE          "\x1b[34m"
#define BLUE_FOND     "\x1b[44m"
#define MAGENTA       "\x1b[35m"
#define MAGENTA_FOND  "\x1b[45m"
#define CYAN          "\x1b[36m"
#define CYAN_FOND     "\x1b[46m"
#define WHITE_FOND    "\x1b[47m"
#define COLOR_RESET   "\x1b[0m"

void my_putchar(char c);
void my_putstr(char *str);
int nb_etoiles_actuel(int i);
int nb_etoiles_max(int n);
void my_sapin(int n);
int main(int argc, char *argv[]);

#endif
