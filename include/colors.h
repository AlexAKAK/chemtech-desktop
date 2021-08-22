#include <string.h>
#ifndef COLORS
#define COLORS
#define black "\033[0;30m"
#define red "\033[0;31m"
#define green "\033[0;32m"
#define yellow "\033[0;33m"
#define blue "\033[0;34m"
#define purple "\033[0;35m"
#define cyan "\033[0;36m"
#define white "\033[0;37m"


void print_red(char c) {
    printf(red);
    printf("%c", c);
    printf(white);
}


void print_cyan(char c) {
    printf(cyan);
    printf("%c", c);
    printf(white);
}

void print_purple(char c) {
    printf(purple);
    printf("%c", c);
    printf(white);
}


void print_yellow(char c) {
    printf(yellow);
    printf("%c", c);
    printf(white);
}

void print_green(char c) {
    printf(green);
    printf("%c", c);
    printf(white);
}


void print_nucleotide(char c) {
    if (c == 'a') print_red(c);
    if (c == 't') print_cyan(c);
    if (c == 'u') print_purple(c);
    if (c == 'c') print_yellow(c);
    if (c == 'g') print_green(c);
}

void print_strand(const char * strand) {
    unsigned int i = 0;
    for (i; i < strlen(strand); i++) {
        print_nucleotide(strand[i]);
    }
    printf("\n");
}


#endif