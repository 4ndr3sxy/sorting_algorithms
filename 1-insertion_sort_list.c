#include "sort.h"
#include <unistd.h>

/**
 * insertion_sort_list - sort a double linked list and print each change
 * @list: double pointer to head of linked list
 * Return: Without return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *currentN = *list, *crrntNP = NULL, *beforeN = NULL, *afterN = NULL;
	int valuePrev = 0, value = 0;

	if (!list || *list == NULL)
		return;
	while (currentN->next)
	{
		if (currentN->n > currentN->next->n)
		{
			crrntNP = currentN;
			do {
				beforeN = crrntNP->prev;
				if (!beforeN)
				{
					afterN = crrntNP->next, crrntNP->next = crrntNP->next->next;
					crrntNP->next->prev = crrntNP, crrntNP->prev = afterN;
					afterN->next = crrntNP, afterN->prev = NULL, *list = afterN;
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
			currentN = currentN->prev;
		}
		currentN = currentN->next;
	}
}
