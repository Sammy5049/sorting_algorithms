#include "sort.h"



/**
 * swap_head - Swap head node in a liked list
 * @list: Pointer to list head.
 * @node_tail: Pointer to list tail.
 * @shaker: Pointer to current swapping node
 */
void swap_head(listint_t **list, listint_t **node_tail, listint_t **shaker)
{
	listint_t *inter;

	inter = (*shaker)->next;


	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = inter;
	else
		*list = inter;
	inter->prev = (*shaker)->prev;
	(*shaker)->next = inter->next;
	if (inter->next != NULL)
		inter->next->prev = *shaker;
	else
		*node_tail = *shaker;
	(*shaker)->prev = inter;
	inter->next = *shaker;
	*shaker = inter;
}

/**
 * swap_end - Swap end node in a liked list
 * @list: Pointer to list head.
 * @node_tail: Pointer to list tail.
 * @shaker: Pointer to current swapping node
 */
void swap_end(listint_t **list, listint_t **node_tail, listint_t **shaker)
{
	listint_t *inter;

	inter = (*shaker)->prev;


	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = inter;
	else
		*node_tail = inter;
	inter->next = (*shaker)->next;
	(*shaker)->prev = inter->prev;
	if (inter->prev != NULL)
		inter->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = inter;
	inter->prev = *shaker;
	*shaker = inter;
}

/**
 * cocktail_sort_list - Sort doubly-linked list wint cocktail sort
 * @list: Pointer to list  head.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node_tail, *shaker;
	bool shake_not_stir = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node_tail = *list; node_tail->next != NULL;)
		node_tail = node_tail->next;

	while (shake_not_stir == false)
	{
		shake_not_stir = true;
		for (shaker = *list; shaker != node_tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_head(list, &node_tail, &shaker);
				print_list((const listint_t *)*list);
				shake_not_stir = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_end(list, &node_tail, &shaker);
				print_list((const listint_t *)*list);
				shake_not_stir = false;
			}
		}
	}
}
