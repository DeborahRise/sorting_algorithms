#include "sort.h"

/**
 * swap_list - swaps the elements in list
 * @head: head of list
 * @node1: first node to be swapped
 * @node2: 2nd node in question
 * Return: nothing
 */
void swap_list(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: the list in question
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *swap, *temp;

	if (list == NULL || *list == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		swap = i->prev;
		while (swap != NULL && i->n < swap->n)
		{
			swap_list(list, &swap, i);
			print_list((const listint_t *)*list);
		}
	}
}
