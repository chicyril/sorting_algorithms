#include "sort.h"

/**
 * swap_nodes - swap the nodes of a doubly linked list.
 * @list: address of the list.
 * @n1: first node to swap with.
 * @n2: second node.
 **/
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	if (n1->prev)
		n1->prev->next = n2;
	else
		*list = n2;
	n2->prev = n1->prev;
	n1->prev = n2;
	if (n1->next)
		n1->next->prev = n1;
	print_list(*list);
}

/**
 * cocktail_sort_list - implement cocktail sort on a linked list.
 * @list: address of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *trav = NULL;
	bool swapped = true;

	if (!list || !*list || !(*list)->next)
		return;
	trav = *list;
	while (swapped)
	{
		swapped = false;
		while (trav->next != end)
		{
			if (trav->n > trav->next->n)
			{
				swap_nodes(list, trav, trav->next);
				swapped = true;
			}
			else
				trav = trav->next;
		}
		if (!swapped)
			break;
		end = trav;
		trav = trav->prev;
		swapped = false;
		while (trav->prev != start)
		{
			if (trav->n < trav->prev->n)
			{
				swap_nodes(list, trav->prev, trav);
				swapped = true;
			}
			else
				trav = trav->prev;
		}
		start = trav;
		trav = trav->next;
	}
}
