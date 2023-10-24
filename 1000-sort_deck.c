#include "deck.h"

/**
 * string_cmp - Compares two strings.
 * @s1: 1st string.
 * @s2: 2nd string.
 *
 * Return: +ve byte diff if s1 > s2
 *         0 if s1 == s2
 */
int string_cmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_card_value - func to get the numerical value of card.
 * @card: pointer to deck_node_t card.
 * Return: numerical value of card.
 */
char get_card_value(deck_node_t *card)
{
	if (string_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (string_cmp(card->card->value, "1") == 0)
		return (1);
	if (string_cmp(card->card->value, "2") == 0)
		return (2);
	if (string_cmp(card->card->value, "3") == 0)
		return (3);
	if (string_cmp(card->card->value, "4") == 0)
		return (4);
	if (string_cmp(card->card->value, "5") == 0)
		return (5);
	if (string_cmp(card->card->value, "6") == 0)
		return (6);
	if (string_cmp(card->card->value, "7") == 0)
		return (7);
	if (string_cmp(card->card->value, "8") == 0)
		return (8);
	if (string_cmp(card->card->value, "9") == 0)
		return (9);
	if (string_cmp(card->card->value, "10") == 0)
		return (10);
	if (string_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (string_cmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_sort_deck_kind - func to sort cards from spades to diamonds.
 * @deck: pointer to head of doubly-linked list.
 */
void insert_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *i, *inst, *temp;

	for (i = (*deck)->next; i != NULL; i = temp)
	{
		temp = i->next;
		inst = i->prev;
		while (inst != NULL && inst->card->kind > i->card->kind)
		{
			inst->next = i->next;
			if (i->next != NULL)
				i->next->prev = inst;
			i->prev = inst->prev;
			i->next = inst;
			if (inst->prev != NULL)
				inst->prev->next = i;
			else
				*deck = i;
			inst->prev = i;
			inst = i->prev;
		}
	}
}

/**
 * insert_sort_deck_value - func to Sort deck of cards
 * @deck: pointer to head of doubly-linked list.
 */
void insert_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *i, *inst, *temp;

	for (i = (*deck)->next; i != NULL; i = temp)
	{
		temp = i->next;
		inst = i->prev;
		while (inst != NULL &&
			   inst->card->kind == i->card->kind &&
			   get_card_value(inst) > get_card_value(i))
		{
			inst->next = i->next;
			if (i->next != NULL)
				i->next->prev = inst;
			i->prev = inst->prev;
			i->next = inst;
			if (inst->prev != NULL)
				inst->prev->next = i;
			else
				*deck = i;
			inst->prev = i;
			inst = i->prev;
		}
	}
}

/**
 * sort_deck - func to Sort deck of cards from ace - king
 * @deck: pointer to head of linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insert_sort_deck_kind(deck);
	insert_sort_deck_value(deck);
}
