/* unit_list.c: Test List Structure */

#include "lsort.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* Constants */

char *STRINGS[] = {
    "deadpool",
    "spider-man",
    "batman",
    "rogue",
    "phoenix",
    NULL
};

/* Macros */

#define streq(a, b) (strcmp(a, b) == 0)

/* Tests */

int test_00_list_push_back() {
    List *l = list_create();
    assert(l);

    size_t n = 0;
    for (char **s = STRINGS; *s; s++, n++) {
    	list_push_back(l, *s);
    }
    assert(l->size == n);

    Node *curr = l->head;
    for (char **s = STRINGS; *s && curr; s++, curr = curr->next) {
        assert(streq(*s, curr->data));
    }

    l = list_delete(l);
    assert(!l);
    return EXIT_SUCCESS;
}

int test_01_list_reverse() {
    List *l = list_create();
    assert(l);

    size_t n = 0;
    for (char **s = STRINGS; *s; s++, n++) {
    	list_push_back(l, *s);
    }
    assert(l->size == n);
    list_reverse(l);

    Node *curr = l->head;
    for (size_t i = 1; curr; i++, curr = curr->next) {
        assert(streq(STRINGS[n - i], curr->data));
    }

    l = list_delete(l);
    assert(!l);
    return EXIT_SUCCESS;
}

int test_02_list_sort() {
    List *l = list_create();
    assert(l);

    size_t n = 0;
    for (char **s = STRINGS; *s; s++, n++) {
    	list_push_back(l, *s);
    }
    assert(l->size == n);
    list_sort(l);

    Node *curr = l->head;
    Node *next = l->head->next;
    while (next) {
        assert(strcmp(curr->data, next->data) < 0);
        curr = next;
        next = next->next;
    }

    l = list_delete(l);
    assert(!l);
    return EXIT_SUCCESS;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "Usage: %s NUMBER\n\n", argv[0]);
	fprintf(stderr, "Where NUMBER is right of the following:\n");
	fprintf(stderr, "    0  Test list_push_back\n");
	fprintf(stderr, "    1  Test list_reverse\n");
	fprintf(stderr, "    2  Test list_sort\n");
	return EXIT_FAILURE;
    }

    int number = atoi(argv[1]);
    int status = EXIT_FAILURE;

    switch (number) {
	case 0:  status = test_00_list_push_back(); break;
	case 1:  status = test_01_list_reverse(); break;
	case 2:  status = test_02_list_sort(); break;
	default: fprintf(stderr, "Unknown NUMBER: %d\n", number); break;
    }

    return status;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
