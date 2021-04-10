/* lsort.c: Sorting Utility Using Linked-Lists */

#include "lsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char * PROGRAM_NAME = NULL;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s\n", PROGRAM_NAME);
    fprintf(stderr, "  -r   reverse the result of comparisons\n");
    exit(status);
}

void lsort(FILE *stream, bool reverse) {
    // TODO
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int  argind  = 1;
    bool reverse = false;

    /* Parse command line arguments */
    PROGRAM_NAME = argv[0];
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];
        switch (arg[1]) {
            case 'r':
            	reverse = true;
            	break;
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }

    /* Sort using list */
    lsort(stdin, reverse);
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
