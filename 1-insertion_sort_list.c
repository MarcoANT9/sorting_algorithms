#include "sort.h"
#define NULL 0

/**
 * swap_for - Swaps a node forwards the linked list.
 *
 * @current: Current node in the linked list to move forward.
 * @list: List head.
 *
 * Description - This function takes a node and swaps it with the next one.
 *
 * Return: Nothing (void).
 *
 */
void swap_for(listint_t **current, listint_t **list)
{
	listint_t *tmp;

	tmp = (*current)->next;
	if ((*current)->next == NULL)
		return;
	tmp->prev = (*current)->prev;
	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*list = tmp;
	(*current)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = (*current);
	tmp->next = (*current);
	(*current)->prev = tmp;
}

/**
 * swap_bac - Swaps a node backwards the linked list.
 *
 * @tmp: Current node in the linked list to move backwards.
 *
 * @head: Head of the linked list.
 *
 * Description - This function takes a node and swaps it with the previous one.
 *
 * Return: Nothing (void).
 *
 */
void swap_bac(listint_t **tmp, listint_t **head)
{

	listint_t *back;


	back = (*tmp)->prev;

	if (back->prev != NULL)
		back->prev->next = (*tmp);
	else
		*head = *tmp;
	(*tmp)->prev = back->prev;
	back->next = (*tmp)->next;
	if ((*tmp)->next != NULL)
		(*tmp)->next->prev = back;
	(*tmp)->next = back;
	back->prev = (*tmp);

}

/**
 * insertion_sort_list - This Function
 *
 * @list: Address of the linked list to sort.
 *
 *
 *
 * Description - This program takes a linked list and travers it sorting its
 *               contents; it will look at a node, then the next one, if the
 *               value of the next node is bigger than the value of the current
 *               node, they get swapped, then the program will look back at the
 *               list, if the node before the swapped one has a bigger value,
 *               they get swapped again, then it repeats until it finds a value
 *               lower than the first swapped value. Then the program will
 *               continue until the current node reaches NULL.
 *
 * Return: Nothing (void).
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	current = *list;

	if (!list || !*list || !current->next)
		return;

	while (current)
	{
		if (current->next && current->n > current->next->n)
		{
			swap_for(&current, list);
			print_list(*list);

			tmp = current->prev;
			while (tmp->prev && tmp->n < tmp->prev->n)
			{
				swap_bac(&tmp, list);
				print_list(*list);
			}
		}
		else
			current = current->next;
	}

}
