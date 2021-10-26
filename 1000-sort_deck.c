#include "deck.h"

/**
 * sort_cards - sort card regardless the diference in index
 * @pointersTrans: Pointers to address in the first node to replace
 * @pointersReceiver: Pointers to address in the second node to replace
 * @deck: head
 * Return: without return
 */
void sort_cards(deck_node_t *pointersTrans[],
				deck_node_t *pointersReceiver[], deck_node_t **deck)
{
	pointersTrans[1]->next = pointersReceiver[2];
	pointersTrans[1]->prev = pointersReceiver[0];
	if (pointersReceiver[0])
	{
		pointersReceiver[0]->next = pointersTrans[1];
	}
	if (pointersReceiver[2])
	{
		pointersReceiver[2]->prev = pointersTrans[1];
	}

	pointersReceiver[1]->next = pointersTrans[2];
	pointersReceiver[1]->prev = pointersTrans[0];
	if (pointersTrans[2])
	{
		pointersTrans[2]->prev = pointersReceiver[1];
	}
	if (pointersTrans[0])
	{
		pointersTrans[0]->next = pointersReceiver[1];
	}
	else
	{
		*deck = pointersReceiver[1];
	}
}

/**
 * sort_cards_close - Function to sort card with 1 index of diference
 * @crrntNP: Node currently
 * @deck: head
 * Return: without return
 */
void sort_cards_close(deck_node_t *crrntNP, deck_node_t **deck)
{
	deck_node_t *beforeN = NULL, *afterN = NULL;

	beforeN = crrntNP->prev;
	if (!beforeN)
	{
		afterN = crrntNP->next, crrntNP->next = crrntNP->next->next;
		if (!crrntNP->next)
		{
			*deck = afterN, afterN->next = afterN->prev;
			afterN->prev = NULL, afterN->next->next = NULL;
			afterN->next->prev = afterN;
		}
		else
		{
			crrntNP->next->prev = crrntNP, crrntNP->prev = afterN;
			afterN->next = crrntNP, afterN->prev = NULL, *deck = afterN;
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
}

/**
 * validate_node - validate if it is in the correct position
 * @currentNode: Node currently
 * @position: as an index
 * Return: int with the number in the correct position
 */
int validate_node(deck_node_t *currentNode, int position)
{
	int valueCard = 0, valueType = 0, countTotal = 0;

	valueCard = atoi(currentNode->card->value);
	if (!valueCard)
	{
		switch (*currentNode->card->value)
		{
		case 'A':
			valueCard = 1;
			break;
		case 'J':
			valueCard = 11;
			break;
		case 'Q':
			valueCard = 12;
			break;
		case 'K':
			valueCard = 13;
			break;
		default:
			valueCard = 0;
			break;
		}
	}
	valueType = currentNode->card->kind * 13;
	countTotal = valueCard + valueType - position - 1;
	return (countTotal);
}

/**
 * sort_deck - sort a deck of cards (A-K, S,H,C,D)
 * @deck: double pointer of the head of linked list
 * Return: without return
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *temporal = NULL, *temporalLogic = NULL;
	deck_node_t *pointersTrans[] = {NULL, NULL, NULL};
	deck_node_t *pointersReceiver[] = {NULL, NULL, NULL};
	int currentPosition = 0, validatePosition = 0, x = 0;

	for (x = 0; x < 10; x++, temporal = *deck, currentPosition = 0)
	{
		temporal = *deck;
		while (temporal)
		{
			validatePosition = validate_node(temporal, currentPosition);
			if (validatePosition != 0)
			{
				if (validatePosition == 1)
				{
					sort_cards_close(temporal, deck);
					break;
				}
				else
				{

					temporalLogic = temporal;
pointersTrans[0] = temporalLogic->prev, pointersTrans[1] = temporalLogic;
					pointersTrans[2] = temporalLogic->next;
					while (validatePosition != 0)
					{
					if (validatePosition > 0)
					temporalLogic = temporalLogic->next, validatePosition--;
					else
					temporalLogic = temporalLogic->prev, validatePosition++;
					}
pointersReceiver[0] = temporalLogic->prev, pointersReceiver[1] = temporalLogic;
					pointersReceiver[2] = temporalLogic->next;
					sort_cards(pointersTrans, pointersReceiver, deck);
					temporal = pointersReceiver[1];
				}
			}
			temporal = temporal->next, currentPosition++;
		}
	}
}
