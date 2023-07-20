#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 *			of integers in ascending order
 *			using Insertion Sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;

			current->next = prev;
			prev->prev = current;

			prev = current->prev;
			print_list(*list);
		}

		current = next_node;
	}
}
