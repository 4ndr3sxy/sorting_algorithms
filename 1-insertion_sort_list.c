#include "sort.h"
#include <unistd.h>

/**
 * sort_nodes - Logic to sort linked list
 * @crrntNP: node when init the logic
 * @list: pointer to header
 * Return: Without return
 */
void sort_nodes(listint_t *crrntNP, listint_t **list)
{
	listint_t *beforeN = NULL, *afterN = NULL;
	int valuePrev = 0, value = 0;

	do {
		beforeN = crrntNP->prev;
		if (!beforeN)
		{
			afterN = crrntNP->next, crrntNP->next = crrntNP->next->next;
			if (!crrntNP->next)
			{
				*list = afterN, afterN->next = afterN->prev;
				afterN->prev = NULL, afterN->next->next = NULL;
				afterN->next->prev = afterN;
			}
			else
			{
				crrntNP->next->prev = crrntNP, crrntNP->prev = afterN;
				afterN->next = crrntNP, afterN->prev = NULL, *list = afterN;
			}
		}
		else if (!beforeN->next->next->next)
		{
			beforeN->next = beforeN->next->next;
			beforeN->next->next = beforeN->next->prev;
			beforeN->next->prev = beforeN, beforeN->next->next->next = NULL;
			beforeN->next->next->prev = beforeN->next, crrntNP = crrntNP->prev;
		}
		else
		{
			beforeN->next = beforeN->next->next;
			beforeN->next->prev = beforeN, afterN = beforeN->next->next;
			beforeN->next->next = crrntNP, beforeN->next->next->prev = beforeN->next;
			beforeN->next->next->next = afterN;
			afterN->prev = beforeN->next->next, crrntNP = crrntNP->prev;
		}
		print_list(*list);
		value = crrntNP->n, valuePrev = crrntNP->prev->n, crrntNP = crrntNP->prev;
	} while (value < valuePrev);
}

/**
 * insertion_sort_list - sort a double linked list and print each change
 * @list: double pointer to head of linked list
 * Return: Without return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *currentN = NULL, *crrntNP = NULL;

	if (!list || !*list)
		return;
	currentN = *list;
	while (currentN->next)
	{
		if (currentN->n > currentN->next->n)
		{
			crrntNP = currentN;
			sort_nodes(crrntNP, list);
			currentN = currentN->prev;
		}
		currentN = currentN->next;
	}
}
