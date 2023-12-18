#include"sort.h"

/**
 * insertion_sort_list - implement insertion sort on a linked list
 * @list: doubly linked list to be sorted.
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *trav = NULL, *swap = NULL, *shift = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	trav = (*list)->next;
	while (trav)
	{
		if (trav->prev->n < trav->n)
		{
			trav = trav->next;
			continue;
		}
		shift = trav;
		swap = shift->prev;
		trav = trav->next;
		while (swap && (swap->n > shift->n))
		{
			shift->prev = swap->prev;
			if (swap->prev)
				swap->prev->next = shift;
			else
				*list = shift;
			swap->prev = shift;
			swap->next = shift->next;
			if (shift->next)
				shift->next->prev = swap;
			shift->next = swap;
			swap = shift->prev;
			print_list(*list);
		}
	}
}
