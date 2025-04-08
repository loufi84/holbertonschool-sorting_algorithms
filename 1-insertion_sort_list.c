#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 *						in ascending order using the insertion sort algorithm
 *
 * @list: The list containing the integers
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = (*list)->next, *next_node;
	listint_t *current, *prev, *tmp;

	while (node != NULL)
	{
		current = node;
		prev = current->prev;

		next_node = node->next;
		while (prev != NULL && current->n < prev->n)
		{
			tmp = prev->prev;
			if (tmp != NULL)
				tmp->next = current;
			current->prev = tmp;
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			prev->prev = current;
			if (tmp == NULL)
				*list = current;
			prev = current->prev;
			print_list(*list);
		}
		node = next_node;
	}
}
