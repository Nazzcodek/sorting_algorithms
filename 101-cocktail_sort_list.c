#include "sort.h"

/**
 * forward_pass - Performs the forward pass of the Cocktail Shaker Sort
 *
 * @list: Double pointer to the head of the list
 * @tail: Pointer to the tail of the list
 *
 * Return: 1 if swaps were made, 0 otherwise
 */
int forward_pass(listint_t **list, listint_t *tail)
{
	int swapped = 0;
	listint_t *current = *list;

	while (current->next != tail)
	{
		if (current->n > current->next->n)
		{
			if (current->prev)
				current->prev->next = current->next;
			else
				*list = current->next;

			current->next->prev = current->prev;
			current->prev = current->next;
			current->next = current->next->next;

			if (current->next)
				current->next->prev = current;

			current->prev->next = current;
			swapped = 1;

			print_list(*list);
		}
		else
		{
			current = current->next;
		}
	}

	return (swapped);
}

/**
 * backward_pass - Performs the backward pass of the Cocktail Shaker Sort
 *
 * @list: Double pointer to the head of the list
 * @tail: Pointer to the tail of the list
 *
 * Return: 1 if swaps were made, 0 otherwise
 */
int backward_pass(listint_t **list, listint_t *tail)
{
	int swapped = 0;
	listint_t *current = tail;

	while (current->prev != *list)
	{
		if (current->n < current->prev->n)
		{
			if (current->next)
				current->next->prev = current->prev;
			else
				current->prev->next = NULL;

			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->prev->prev;

			if (current->prev)
				current->prev->next = current;

			current->next->prev = current;
			swapped = 1;

			if (!current->prev)
				*list = current;

			print_list(*list);
		}
		else
		{
			current = current->prev;
		}
	}

	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using Cocktail Shaker Sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *tail = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do
	{
		swapped = 0;
		swapped |= forward_pass(list, tail);
		tail = (tail == NULL) ? *list : tail->prev;

		if (!swapped)
			break;

		swapped |= backward_pass(list, tail);
		tail = (tail == NULL) ? *list : tail->next;
	}
	while (swapped);
}
