#include "sort.h"

/**
 * swap_nodes - A function that swaps two nodes in a doubly linked list
 *
 * @list: Double pointer to the head of the list
 * @node1: The first node to swap
 * @node2: The second node to swap
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{

	if (!node1 || !node2)
		return;
	node1->next = node2->next;
	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * fwd_p - A function that parforms a forward pass of the cocktail sort
 *
 * @list: Double pointer to the head of the list
 * @start: Starting node for the pass
 * @end: Ending node for the pass
 * @swap: Pointer to the swap flag
 *
 * Return: The new endong node
 */

listint_t *fwd_p(listint_t **list, listint_t *start, listint_t *end, int *swap)
{
	listint_t *current = start;

	while (current->next && current->next != end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			*swap = 1;
			print_list(*list);
			if (current->prev)
				current = current->prev;
		}
		else
			current = current->next;
	}
	return (current);

}

/**
 * bck_p - A function that performs a backward pass of the cocktail sort
 *
 * @list: Double pointer to the head of the list
 * @start: Starting node for the pass
 * @end: Ending node for the pass
 * @swap: Pointer to the swap flag
 *
 * Return: The new starting node
 */

listint_t *bck_p(listint_t **list, listint_t *end, int *swap)
{
	listint_t *current = end;

	while (current->prev != NULL)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			*swap = 1;
			print_list(*list);
			if (current->next)
				current = current->next;
		}
		else
			current = current->prev;
	}
	return (current);
}

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 *						in asxending order using the Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swap;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;
	swap = 1;

	while (swap)
	{
		swap = 0;
		end = fwd_p(list, start, end, &swap);
		if (!swap)
			break;
		swap = 0;
		start = bck_p(list, end, &swap);
		if (!swap)
			break;
	}
}
