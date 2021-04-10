/* node.c: Node Structure */

#include "lsort.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create node. 
 *
 * This allocates and configures a node that the user must later deallocate.
 * @param   string      String value.
 * @param   next        Reference to next node.
 * @return  Allocated node structure.
 */
Node *node_create(char *data, Node *next) {
    return NULL;
}

/**
 * Delete node.
 *
 * This deallocates the given node (recursively if specified).
 * @param   n           Node to deallocate.
 * @param   recursive   Whether or not to deallocate recursively.
 * @return  NULL pointer.
 */
Node *node_delete(Node *n, bool recursive) {
    return NULL;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
