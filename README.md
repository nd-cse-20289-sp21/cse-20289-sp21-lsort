# lsort - A simple sorting utility

This is a small project meant to allow you to practice your knowledge of [C],
[dynamic memory], and [data structures].  In particular, you will need build a
[singly-linked list] library and then implement [merge sort] to program your
own version of the [sort] utility in [C], called `lsort`:

    $ ./bin/lsort -h
    Usage: ./bin/lsort
      -r   reverse the result of comparisons

**Note**: This assignment is based heavily on [Homework 07] from
[CSE.20289.SP17].

## Singly-Linked List

For this project, you are to create [singly-linked list] library, `liblsort.a`,
which contains functions for creating a list, deleting a list, adding elements
to a list, reversing a list, and sorting a list.

As discussed in class, arrays in [C] are fast for random access, but have of
the limitation of being **fixed** sized. When we need a data structure that can
grow organically at run-time, we can turn to the [singly-linked list].

Recall from your [data structures] course that a singly-linked list is a data
structure which consists of **linked** nodes. That is, it is a [sequence
container] of **node structures** where each **node** consists of a **data
value** and a reference to the next node in the sequence as shown below:

![Singly-Linked List](https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/img/linked-list.png)

For our library, we will be using a [singly-linked list] with a **tail
pointer** and a **stored size**:

- As with a normal [singly-linked list], we will have a series of individual
  **node structures** which consist of a **data value** and a reference to the
  **next node**.

    In the diagram above, we have three individual **node structures** holding
    the values `5`, `7`, and `4`. The `5` node has a reference to the `7` node,
    while the `7` node has a reference to the `4` node. Because there is
    nothing after the `4` node, the `4` node's next node reference is simply
    the `NULL` pointer.

    This is useful because it allows us to iterate through our sequence using
    the following **pseudo-code**:

        for (curr = head; curr != NULL; curr = curr.next)
            visit(curr)

- To keep track of our nodes, we have a **list structure** that tracks the
  `head` of the list, the `tail` of the list, and the `size` of the list.

    In the diagram above, `head` references the first **node structure**, which
    is the `5` node.  Similarly, `tail` references the last **node structure**,
    which is the `4` node.  Finally, `size` has the value of `3` since the
    [sequence container] has `3` elements.

- Because our [singly-linked list] has both a `tail` pointer, we can insert new
  node structures to the back of the [sequence container] in
  **constant time** (ie. `O(1)`).

- Because we maintain the `size` of the list in the **list structure**, we do
  not need to iterate through the [sequence container] to compute this value
  and thus can report the number of elements in **constant time**.

## Starter Code

To help you get started, this repository contains the following starter code:

    lsort
        \_  Makefile    # This is the Makefile for building all the project artifacts
        \_  bin         # This folder contains the project scripts and executables
        \_  include     # This folder contains the project header files
        \_  lib         # This folder contains the project library
        \_  src         # This folder contains the project source code
        \_  tests       # This folder contains the project test source code

###  Node Structure

The `node.h` file is the [header] file for the **node structure** used in our
implementation of a [singly-linked list]. Besides a few function prototypes,
this header defines a `Node` as:

    struct Node {
        char *data;
        Node *next;
    };

This means that each **Node** consists of a string **data value**, and a
**reference** to the **next node** in the sequence.

The `node.c` file contains the implementation for the **node structure**. For
this project, you will need to implement the following functions:

1. `Node *node_create(char *data, Node *next)`

    > This function allocates a new `Node` structure, sets its `data`, and
    `next` fields, and returns the allocated structure.

    - You must check if memory allocation fails.
    - You must allocate and copy the string (consider [strdup]).

2. `Node * node_delete(struct node *n, bool recursive)`

    > This function deallocates the given `Node` structure (including the
    `data` field). If `recursive` is `true` this function will also deallocate
    the next `Node` and any of its successors.

    - Although the `recursive` parameter implies you should use [recursion],
      you may wish to consider using an **iterative** implementation instead to
      avoid [stack overflow].

###  List Structure

The `list.h` file is the [header] file for the **list structure** used in our
implementation of a [singly-linked list]. Besides a few function prototypes,
this header defines a `List` as:

    struct List {
        Node  *head;
        Node  *tail;
        size_t size;
    }

This reflects the design describe above. Each `List` has a **reference** to the
`head` of the list (ie. first element), the `tail` of the list (ie. last
element), and the `size` of the list (ie. number of elements).

The `list.c` file contains the implementation for the **list structure**. For
this project, you will need to implement the following functions:

1. `List *list_create()`

    > This function allocates a new `List` structure, initializes its fields,
    and returns the allocate structure.

    - Consider using [calloc].

2. `List *list_delete(List *l)`

    > This function deallocates the given `List` structure.

    - You should use the `node_delete` function.

3. `void list_push_back(List *l, char *s)`

    > This function adds a new `Node` structure with the given `s` string value
    to the back of the `List` structure.

    - Be sure to update the `head` and `tail` of the `List` structure
      appropriately.

    - You should use the `node_create` function.

4. `void list_reverse(List *l)`

    > This function reverses the `List` structure recursively using the
    internal `node_reverse` function.

    - Draw a picture on a piece of paper and do this by hand first.

    - `node_reverse` takes in the current `Node` and what its previous `Node`
      is.  Because we are reversing the `List`, we want to end up saying the
      the `next` field of the current `Node` is the previous `Node`.

    - Remember to update the `head` and `tail` fields of the `List` structure.

5. `void list_sort(List *l)`

    > This function performs [merge sort], which is a recursive [divide and
    conquer] sorting algorithm, on the `List` structure using the internal
    `list_merge_sort`, `list_split`, and `list_merge` functions.

    - Draw a picture on a piece of paper and do this by hand first.

    - The `list_merge_sort` function has the following **pseudo-code**:

            # Divide
            split(head, &left, &right)

            # Conquer
            left  = merge_sort(left)
            right = merge_sort(right)

            # Combine
            head = merge(left, right)

    - The `list_split` function divides the provided `List` into `left` and
      `right` sublists by using the fast and slow pointer trick. Be sure to
      `NULL` terminate your sublists.

    - The `list_merge` function **iteratively** combines two sublists into a
      single **ordered** list.

    - Remember to update the `head` and `tail` fields of the `List` structure.

### lsort utility

The `lsort.c` file is contains the implementation of the list sorting tool
described above. For this project, you need to implement the following
function:

1. `void lsort(FILE *stream, bool reverse)`

    > This function reads one line at a time from the `stream` and builds a
    [singly-linked list] using `list_push_back`.  It then sorts the list using
    `list_sort`.  If `reverse` is `true`, then the list is reversed using
    `list_reverse`.  Finally, this function will print the `data` attribute of
    each element in the list.

## Building

To build the project, you can simply run the `make` command:

    $ make
    Compiling src/lsort.o
    Compiling src/node.o
    Compiling src/list.o
    Linking lib/liblsort.a
    Linking bin/lsort

This will compile both the project library and executable.  To remove these
artifacts, you can use `make clean`:

    $ make clean
    Removing objects
    Removing static library
    Removing tests
    Removing lsort

## Testing

To test your project, you can use the provided unit and functional tests:

    $ make test
    Testing node...
     node_create                              ... Success
     node_delete                              ... Success

       Score 1.00

    Testing list...
     list_push_back                           ... Success
     list_reverse                             ... Success
     list_sort                                ... Success

       Score 3.00

    Testing bin/lsort ...
     Usage                                    ... Success
     lsort    on /etc/passwd                  ... Success
     lsort -r on /etc/passwd                  ... Success
     lsort    on /etc/hosts                   ... Success
     lsort -r on /etc/hosts                   ... Success
     lsort    on seq 1000 | shuf              ... Success
     lsort -r on seq 1000 | shuf              ... Success

       Score 4.00

**Note**, you can each test individually:

    $ ./bin/unit_node 0     # Run unit test 0 of node structure

    $ ./bin/test_lsort.sh   # Run functional test of lsort

[Homework 07]:          https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/homework07.html
[CSE.20289.SP17]:       https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/
[data structures]:      https://en.wikipedia.org/wiki/Data_structure
[singly-linked list]:   https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list
[sort]:                 http://man7.org/linux/man-pages/man1/sort.1.html
[C]:                    https://en.wikipedia.org/wiki/C_(programming_language)
[dynamic memory]:       https://en.wikipedia.org/wiki/C_dynamic_memory_allocation
[sequence container]:   https://en.wikipedia.org/wiki/List_(abstract_data_type)
[header]:               https://en.wikipedia.org/wiki/Include_directive#C.2FC.2B.2B
[strdup]:               http://man7.org/linux/man-pages/man3/strdup.3.html
[recursion]:            https://en.wikipedia.org/wiki/Recursion
[stack overflow]:       https://en.wikipedia.org/wiki/Stack_overflow
[strdup]:               http://man7.org/linux/man-pages/man3/strdup.3.html
[calloc]:               http://man7.org/linux/man-pages/man3/malloc.3.html
[merge sort]:           https://en.wikipedia.org/wiki/Merge_sort
[divide and conquer]:   https://en.wikipedia.org/wiki/Divide_and_conquer_algorithm
