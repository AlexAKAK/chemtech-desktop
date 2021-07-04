#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

void scan_mRNA_and_print_each_aa(char mRNA[]) {

    const unsigned int mRNA_len = strlen(mRNA);

    while (1) {
        // getting the codon
        char codon[4]; // add 1 extra byte for the null byte
        memcpy(codon, mRNA, 3);
        codon[4] = '\0';

        printf(codon);

    }

}

const char * get_aa_from_codon_using_codon_to_aa(const char * codon, struct pair codon_to_aa[]) {
    unsigned int i = 0;
    for (i; i < 64; i++) {
        // check if the codon equals the key at the i position in the codon_to_aa hashtable
        if (strcmp(codon, codon_to_aa[i].key) == 0) {
            return codon_to_aa[i].val; printf(codon);
        }
    }
}