/* lsort.h: sorting linked-list */

#ifndef LSORT_H
#define LSORT_H

#include <stdbool.h>
#include <stdio.h>

/* Node Structure */

typedef struct Node Node;
struct Node {
    char *data;
    Node *next;
};

Node *node_create(char *data, Node *next);
Node *node_delete(Node *n, bool recursive);

/* List Structure */

typedef struct List List;
struct List {
    Node  *head;
    Node  *tail;
    size_t size;
};

List *list_create();
List *list_delete(List *l);

void  list_push_back(List *l, char *s);
void  list_reverse(List *l);
void  list_sort(List *l);

#endif

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
