#include <stdio.h>
#include "sort.h"
/**
 * swap - swap two nodes in the doubly linked list
 * @head: pointer to the head node
 * @first_node: pointer to the first node
 * @second_node: pointer to the second node
 * Return: nothing!
 */

void swap(listint_t **head, listint_t **first_node, listint_t *second_node)
{
	/* update the next pointer to point to the same node */
	(*first_node)->next = second_node->next;

	if (second_node->next)
	{
		second_node->next->prev = *first_node;
	}
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;

	if ((*first_node)->prev)
	{
		(*first_node)->prev->next = second_node;
	}
	else
	{
		*head = second_node;
	}

	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}

/**
 * insertion_sort_list - uses insertion sort algorithm to sort a list
 * of numbers in a doubly linked list
 * @list: pointer to the head of the list
 * Return: Nothing!
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *new;

	if (list && *list && (*list)->next)
	{
		current = (*list)->next;
		while (current)
		{
			tmp = current->next;
			new = current->prev;
			while (new && current->n < new->n)
			{
				swap(list, &new, current);
				print_list((const listint_t *)*list);
			}
			current = tmp;
		}
	}
}
