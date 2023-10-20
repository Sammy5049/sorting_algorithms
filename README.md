C - Sorting algorithms & Big O

#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

Tasks
0. Bubble sort


Write a function that sorts an array of integers in ascending order using the Bubble sort algorithm

Prototype: void bubble_sort(int *array, size_t size);
You’re expected to print the array after each time you swap two elements (See example below)
Write in the file 0-O, the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case
alex@/tmp/sort$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


Write a function that sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm

Prototype: void insertion_sort_list(listint_t **list);
You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
You’re expected to print the list after each time you swap two elements (See example below)
Write in the file 1-O, the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case
alex@/tmp/sort$ cat 1-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


2. Selection sort


Write a function that sorts an array of integers in ascending order using the Selection sort algorithm

Prototype: void selection_sort(int *array, size_t size);
You’re expected to print the array after each time you swap two elements (See example below)
Write in the file 2-O, the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case
alex@/tmp/sort$ cat 2-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

12. Dealer

Write a function that sorts a deck of cards.

Prototype: void sort_deck(deck_node_t **deck);
You are allowed to use the C standard library function qsort
Please use the following data structures:
typedef enum kind_e