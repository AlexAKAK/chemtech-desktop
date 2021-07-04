#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int sub_str(const char * source, unsigned int ending_index, char * dest) {
    char * result = (char *) malloc(sizeof(char) * ending_index + 1);
    result[0] = '\0';


    strncat(dest, source, ending_index + 1);    


    return EXIT_SUCCESS;
}