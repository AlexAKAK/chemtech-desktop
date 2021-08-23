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


#define STRCMP_BOOL char
#define STRCMP_TRUE 0
#define STRCMP_FALSE -1


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
            return codon_to_aa[i].val;
        }
    }
}

void translate(char * mRNA) {
    printf("mRNA Strand: ");
    print_strand(mRNA);
    printf("\n-----------------\n");

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

void complementary(char * strand) {
    size_t length = strlen(strand);
    char * complementary_strand = malloc(length * sizeof(char) + sizeof(char));
    int i = 0;
    for (i; i < length; i++) {
        if (strand[i] == 'a') complementary_strand[i] = 't';
        if (strand[i] == 't') complementary_strand[i] = 'a';
        if (strand[i] == 'c') complementary_strand[i] = 'g';
        if (strand[i] == 'g') complementary_strand[i] = 'c';
        if (strand[i] == 'u') complementary_strand[i] = 'a';
    }
    // add the null byte
    complementary_strand[length] = '\0';

    print_strand(complementary_strand);
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

void transcribe(char * DNA) {
    printf("DNA Strand: ");
    printf(yellow);
    printf(DNA);
    printf(white);
    printf("\n-----------------\n");

    size_t length = strlen(DNA);
    char * mRNA = malloc(sizeof(char) * length + sizeof(char));
    unsigned int i = 0;
    for (i; i < length; i++) {
        if (DNA[i] == 'a') mRNA[i] = 'u';
        if (DNA[i] == 't') mRNA[i] = 'a';
        if (DNA[i] == 'c') mRNA[i] = 'g';
        if (DNA[i] == 'g') mRNA[i] = 'c';
    }

    mRNA[length] = '\0';    

    print_strand(mRNA);
}

int main(int argc, char *argv[]) {

    fill_codon_to_aa_with_data();

    if (argc <= 2) {
        printf("You must provide a nucleotide sequence and an action");
        return EXIT_FAILURE;
    }

    if (argc > 3) {
        printf("You must provide 2 command line arguments");
        return EXIT_FAILURE;
    }

    char * action = argv[1];
    char * strand = argv[2];


    if (strlen(strand) % 3 != 0) {
        printf("Strand length must be divisible by 3.");
        return EXIT_FAILURE;
    }

    if (strcmp(action, "transcribe") == 0) {
        transcribe(strand);
    }
    if (strcmp(action, "translate") == 0) {
        translate(strand);
    }
    if (strcmp(action, "complementary") == 0) {
        complementary(strand);
    }
    
    if (strcmp(action, "commands") == 0) {
        printf("transcribe\ntranslate\ncomplementary\n");
    }

    getchar();
    return EXIT_SUCCESS;
    
}
