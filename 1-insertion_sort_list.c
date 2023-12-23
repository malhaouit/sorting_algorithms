#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
* @list: A pointer to the list to be sorted
*
* Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || !(*list)->next)
		return;

	for (current = (*list)->next; current; current = temp)
	{
		temp = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list((const listint_t *)*list);
		}
	}
}
