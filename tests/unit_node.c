/* unit_node.c: Test Node Structure */

#include "lsort.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* Macros */

#define streq(a, b) (strcmp(a, b) == 0)

/* Tests */

int test_00_node_create() {
    Node *n0 = node_create("californication", NULL);
    assert(n0);
    assert(n0->data);
    assert(streq(n0->data, "californication"));
    assert(n0->next == NULL);
    
    Node *n1 = node_create("otherside", n0);
    assert(n1);
    assert(n1->data);
    assert(streq(n1->data, "otherside"));
    assert(n1->next == n0);

    free(n0->data);
    free(n0);
    free(n1->data);
    free(n1);
    return EXIT_SUCCESS;
}

int test_01_node_delete() {
    Node *n0 = node_create("californication", NULL);
    assert(n0);
    assert(n0->data);
    assert(streq(n0->data, "californication"));
    assert(n0->next == NULL);
    
    n0 = node_delete(n0, false);
    assert(n0 == NULL);

    Node *n1 = node_create("tail", NULL);
    assert(n1);
    n0 = node_create("head", n1);
    assert(n0);

    n0 = node_delete(n0, true);
    assert(n0 == NULL);
    return EXIT_SUCCESS;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
	fprintf(stderr, "Where NUMBER is right of the following:\n");
	fprintf(stderr, "    0  Test node_create\n");
	fprintf(stderr, "    1  Test node_delete\n");
	return EXIT_FAILURE;
    }

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
	case 0:  status = test_00_node_create(); break;
	case 1:  status = test_01_node_delete(); break;
	default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }

    return status;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
