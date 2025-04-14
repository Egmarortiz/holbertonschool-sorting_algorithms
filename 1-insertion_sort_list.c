#include "sort.h"
#include <stdlib.h>

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list.
 * @head: pointer to the head pointer.
 * @node1: pointer to the first node.
 * @node2: pointer to the second node.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*head = node2;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node1->next = node2->next;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order using insertion sort.
 * @list: pointer to the head pointer.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list)
		return;
	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
	}
}

