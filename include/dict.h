#include "aa.h"
#include <string.h>

#define NUMBER_OF_CODONS 64



struct pair {
    const char * key;
    const char * val;
};

unsigned int i = 0; 
void add_pair_to_dict(const char * key, const char * val, struct pair *dict_pair_p) {
    struct pair p;
    p.key = key;
    p.val = val;

    *dict_pair_p = p;
    i++;
}

struct pair codon_to_aa[64];

static void add_pair_to_codon_to_aa(const char * key, const char * val) {
    add_pair_to_dict(key, val, &codon_to_aa[i]);
}

void fill_codon_to_aa_with_data(void) {
    add_pair_to_codon_to_aa("uuu", Phenylalanine);
    add_pair_to_codon_to_aa("uuc", Phenylalanine);
    add_pair_to_codon_to_aa("uua", Leucine);
    add_pair_to_codon_to_aa("uug", Leucine);

    add_pair_to_codon_to_aa("ucu", Serine);
    add_pair_to_codon_to_aa("ucc", Serine);
    add_pair_to_codon_to_aa("uca", Serine);
    add_pair_to_codon_to_aa("ucg", Serine);

    add_pair_to_codon_to_aa("uau", Tyrosine);
    add_pair_to_codon_to_aa("uac", Tyrosine);
    add_pair_to_codon_to_aa("uaa", STOP);
    add_pair_to_codon_to_aa("uag", STOP);

    add_pair_to_codon_to_aa("ugu", Cysteine);
    add_pair_to_codon_to_aa("ugc", Cysteine);
    add_pair_to_codon_to_aa("uga", STOP);
    add_pair_to_codon_to_aa("ugg", Tryptophan);

    add_pair_to_codon_to_aa("cuu", Leucine);
    add_pair_to_codon_to_aa("cuc", Leucine);
    add_pair_to_codon_to_aa("cua", Leucine);
    add_pair_to_codon_to_aa("cug", Leucine);

    add_pair_to_codon_to_aa("ccu", Proline);
    add_pair_to_codon_to_aa("ccc", Proline);
    add_pair_to_codon_to_aa("cca", Proline);
    add_pair_to_codon_to_aa("ccg", Proline);

    add_pair_to_codon_to_aa("cau", Histidine);
    add_pair_to_codon_to_aa("cac", Histidine);
    add_pair_to_codon_to_aa("caa", Glutamine);
    add_pair_to_codon_to_aa("cag", Glutamine);

    add_pair_to_codon_to_aa("cgu", Arginine);
    add_pair_to_codon_to_aa("cgc", Arginine);
    add_pair_to_codon_to_aa("cga", Arginine);
    add_pair_to_codon_to_aa("cgg", Arginine);

    add_pair_to_codon_to_aa("auu", Isoleucine);
    add_pair_to_codon_to_aa("auc", Isoleucine);
    add_pair_to_codon_to_aa("aua", Isoleucine);
    add_pair_to_codon_to_aa("aug", Methionine);

    add_pair_to_codon_to_aa("acu", Threonine);
    add_pair_to_codon_to_aa("acc", Threonine);
    add_pair_to_codon_to_aa("aca", Threonine);
    add_pair_to_codon_to_aa("acg", Threonine);

    add_pair_to_codon_to_aa("aau", Asparagine);
    add_pair_to_codon_to_aa("aac", Asparagine);
    add_pair_to_codon_to_aa("aaa", Lysine);
    add_pair_to_codon_to_aa("aag", Lysine);

    add_pair_to_codon_to_aa("agu", Serine);
    add_pair_to_codon_to_aa("agc", Serine);
    add_pair_to_codon_to_aa("aga", Arginine);
    add_pair_to_codon_to_aa("agg", Arginine);

    add_pair_to_codon_to_aa("ggu", Valine);
    add_pair_to_codon_to_aa("guc", Valine);
    add_pair_to_codon_to_aa("gua", Valine);
    add_pair_to_codon_to_aa("gug", Valine);

    add_pair_to_codon_to_aa("gcu", Alanine);
    add_pair_to_codon_to_aa("gcc", Alanine);
    add_pair_to_codon_to_aa("gca", Alanine);
    add_pair_to_codon_to_aa("gcg", Alanine);
    
    add_pair_to_codon_to_aa("gau", Asparic_Acid);
    add_pair_to_codon_to_aa("gac", Asparic_Acid);
    add_pair_to_codon_to_aa("gaa", Glutamic_Acid);
    add_pair_to_codon_to_aa("gag", Glutamic_Acid);

    add_pair_to_codon_to_aa("ggu", Glycine);
    add_pair_to_codon_to_aa("ggc", Glycine);
    add_pair_to_codon_to_aa("gga", Glycine);
    add_pair_to_codon_to_aa("ggg", Glycine);
}

// one individual codon to aa conversion



