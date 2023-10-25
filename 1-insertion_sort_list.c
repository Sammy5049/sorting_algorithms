#include "sort.h"


/**
 * swap_helper - function to swap node list.
 * @head: pointer to the head of list.
 * @first: pointer to the 1st node swap.
 * @second: pointer to the 2nd node swap.
 */
void swap_helper(listint_t **head, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *first;
	second->prev = (*first)->prev;
	second->next = *first;
	if ((*first)->prev != NULL)
		(*first)->prev->next = second;
	else
		*head = second;
	(*first)->prev = second;
	*first = second->prev;
}


/**
 * insertion_sort_list - function to sorts a list
 * of items in linked list with insertion sort algo
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *insert_itm, *itration, *point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (itration = (*list)->next; itration != NULL; itration = point)
	{
		point = itration->next;
		insert_itm = itration->prev;
		while (insert_itm != NULL && itration->n < insert_itm->n)
		{
			swap_helper(list, &insert_itm, itration);
			print_list((const listint_t *)*list);
		}
	}
}

