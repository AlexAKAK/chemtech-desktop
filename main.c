#include <stdio.h>
#include <stdlib.h>
#include "include/dict.h"
#include "include/aa.h"
#include "include/colors.h"
#include <string.h>

#include "include/str_util.h"


#define BOOL unsigned char
#define TRUE 1
#define FALSE 0
//ok

enum errors {
    NO_ERROR = 0,
    MRNA_MOD_THREE_NOT_0 = 1
};

const char * get_aa_from_codon_using_codon_to_aa(const char * codon, struct pair codon_to_aa[]) {
    unsigned int i = 0;
    for (i; i < 64; i++) {
        // check if the codon equals the key at the i position in the codon_to_aa hashtable
        if (strcmp(codon, codon_to_aa[i].key) == 0) {
            return codon_to_aa[i].val;;
        }
    }
}

void transcribe(char * mRNA) {

    while (strlen(mRNA) != 0) {
        // get the codon
        char * codon = malloc(sizeof (char) * 4);
        codon[0] = '\0';
        sub_str(mRNA, 2, codon);

        // get aa from the codon
        const char * aa = get_aa_from_codon_using_codon_to_aa(codon, codon_to_aa);
        print_aa(aa);

        //shift mRNA to the right by 3 bytes
        mRNA += 3;
        
    }

}

void print_aa_from_codons(const char * mRNA) {
    unsigned int i = 0;
    for (i; i < strlen(mRNA); i += 3) {
        printf("%i", i);
        char * codon = (char *) malloc(sizeof(char) * 4);
        strncpy(codon, mRNA, 4);
        printf(codon);

        mRNA += 3; // moves 3 spaces towards the null terminator
    }

}

void translate(char * DNA) {
    char * mRNA = DNA;
    unsigned int i = 0;
    for (i; i < strlen(mRNA); i++) {
        if (mRNA[i] == 'a') mRNA[i] = 'u';
    }
    i = 0;
    for (i; i < strlen(mRNA); i++) {
        if (mRNA[i] == 'c') mRNA[i] = 'x';
    }
    for (i; i < strlen(mRNA); i++) {
        if (mRNA[i] == 'g') mRNA[i] = 'c';
    }
    for (i; i < strlen(mRNA); i++) {
        if (mRNA[i] == 'x') mRNA[i] = 'g';
    }

    print_strand(mRNA);
}

int main(int argc, char *argv[]) {

    fill_codon_to_aa_with_data();

    if (argc == 2) {
        printf("you must provide an mRNA sequence and an action");
        return EXIT_FAILURE;
    }

    if (argc > 3) {
        printf("You must provide 2 command line arguments");
        return EXIT_FAILURE;
    }

    char * action = argv[1];
    char * strand = argv[2];


    if (strlen(strand) % 3 != 0) {
        printf("mRNA length must be divisible by 3.");
        return EXIT_FAILURE;
    }

    if (strcmp(action, "transcribe")) {
        transcribe(strand);
    }
    if (strcmp(action, "translate")) {
        translate(strand);
    }

    return EXIT_SUCCESS;
}
