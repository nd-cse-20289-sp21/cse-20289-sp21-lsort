/* list.h: List Structure */

#include "lsort.h"

#include <stdlib.h>
#include <string.h>

/* Internal Functions */

Node *  node_reverse(Node *curr, Node *prev);
Node *  list_merge_sort(Node *head);
void    list_split(Node *head, Node **left, Node **right);
Node *  list_merge(Node *left, Node *right);

/* External Functions */

/**
 * Create list.
 *
 * This allocates a list that the user must later deallocate.
 * @return  Allocated list structure.
 */
List *  list_create() {
    return NULL;
}

/**
 * Delete list.
 *
 * This deallocates the given list along with the nodes inside the list.
 * @param   l       List to deallocate.
 * @return  NULL pointer.
 */
List *  list_delete(List *l) {
    return NULL;
}

/**
 * Push back.
 *
 * This adds a new node containing the given string to the back of the list.
 * @param   l       List structure.
 * @param   s       String.
 */
void    list_push_back(List *l, char *s) {
    return;
}

/**
 * Reverse list.
 *
 * This reverses the list.
 * @param   l       List structure.
 */
void    list_reverse(List *l) {
}

/**
 * Reverse node.
 *
 * This internal function recursively reverses the node.
 * @param   curr    The current node.
 * @param   prev    The previous node.
 * @return  The new head of the singly-linked list.
 */
Node *  node_reverse(Node *curr, Node *prev) {
    return NULL;
}

/**
 * Sort list using merge sort.
 *
 * This sorts the list using a custom implementation of merge sort.
 * @param   l       List structure.
 */
void  list_sort(List *l) {
}

/**
 * Performs recursive merge sort.
 *
 * This internal function performs a recursive merge sort on the singly-linked
 * list starting with head.
 * @param   head    The first node in a singly-linked list.
 * @return  The new head of the list.
 */
Node *  list_merge_sort(Node *head) {
    return NULL; 
}

/**
 * Splits the list.
 *
 * This internal function splits the singly-linked list starting with head into
 * left and right sublists.
 * @param   head    The first node in a singly-linked list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 */
void    list_split(Node *head, Node **left, Node **right) {
}

/**
 * Merge sublists.
 *
 * This internal function merges the left and right sublists into one ordered
 * list.
 * @param   left    The left sublist.
 * @param   right   The right sublist.
 * @return  The new head of the list.
 */
Node *  list_merge(Node *left, Node *right) {
    return NULL;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
