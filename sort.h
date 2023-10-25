#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Comparison macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;






void swap_end(listint_t **list, listint_t **node_tail, listint_t **shaker);
void print_array(const int *array, size_t size);
void merge_bito(int *array, size_t size, size_t start, size_t seq,
		char flow);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void merge_sort_rec(int *sub_array, int *buffer, size_t fwd, size_t bck);
void make_max_heap(int *array, size_t size, size_t base, size_t root);
void counting_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int lower, int upper,  size_t size);
void selection_sort(int *array, size_t size);
void print_list(const listint_t *list);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void sub_array_merge(int *sub_array, int *buffer, size_t fwd, size_t mid,
		size_t bck);
void heap_sort(int *array, size_t size);
void sequence_bito(int *array, size_t size, size_t start, size_t seq,
		char flow);
void insertion_sort_list(listint_t **list);
int get_maximum(int *array, int size);
void quick_sort_hoare(int *array, size_t size);
void merge_sort(int *array, size_t size);
int partition_sort(int *array, size_t size, int lower, int upper);
void swap_helper(listint_t **head, listint_t **first, listint_t *second);
void swap_head(listint_t **list, listint_t **node_tail, listint_t **shaker);
void bitonic_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);


#endif
