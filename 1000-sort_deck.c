#include "deck.h"
#include <unistd.h>


void sort_node(deck_node_t *crrntNP, deck_node_t **deck)
{
	deck_node_t *beforeN = NULL, *afterN = NULL;
	int valuePrev = 0, value = 0;

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

int validate_node(deck_node_t *currentNode, int position)
{
	int valueCard = 0, valueType = 0, countTotal = 0;
	printf("POSITION=%d\n", position);

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
		printf("valueCard=%d", valueCard);
	}
	else
	{
		printf("valueCard=%d", valueCard);
	}

	valueType = currentNode->card->kind * 13;
	countTotal = valueCard + valueType - position - 1;
	printf(" and valueType=%d and countTotal=%d\n", valueType, countTotal);
	return (countTotal);
}

void sort_deck(deck_node_t **deck)
{
	deck_node_t *temporal = NULL, *temporalLogic = NULL;
	deck_node_t *pointersTransmitter[] = {NULL, NULL, NULL};
	deck_node_t *pointersReceiver[] = {NULL, NULL, NULL};
	int currentPosition = 0, validatePosition = 0, x = 0;
	;

	do
	{
		write(2, "hola\n", 5);
		temporal = *deck;
		while (temporal)
		{
			validatePosition = validate_node(temporal, currentPosition);
			if (validatePosition != 0)
			{
				if (validatePosition == 1)
				{
					sort_node(temporal, deck);
					break;
				}
				else
				{

					temporalLogic = temporal;
					pointersTransmitter[0] = temporalLogic->prev;
					pointersTransmitter[1] = temporalLogic;
					pointersTransmitter[2] = temporalLogic->next;
					/*printf("%p - %p - %p\n", temporalLogic->prev, temporalLogic, temporalLogic->next);*/
					/*printf("(%s/%d) - (%s/%d)\n", temporalLogic->card->value, temporalLogic->card->kind, temporalLogic->next->card->value, temporalLogic->next->card->kind);*/
					/*printf("%p - %p - %p\n", pointersTransmitter[0], pointersTransmitter[1], pointersTransmitter[2]);
					printf("Current-Value-card=%s, current-kind-card=%d\n", temporalLogic->card->value, temporalLogic->card->kind);
					printf("Address=%p,\n", pointersTransmitter[1]->next);*/
					/*pointersTransmitter[1]->next = pointersTransmitter[0];
					printf("Address=%p,\n", pointersTransmitter[1]->next);*/
					while (validatePosition != 0)
					{
						if (validatePosition > 0)
						{

							temporalLogic = temporalLogic->next, validatePosition--;
						}
						else
						{

							temporalLogic = temporalLogic->prev, validatePosition++;
						}
					}
					pointersReceiver[0] = temporalLogic->prev;
					pointersReceiver[1] = temporalLogic;
					pointersReceiver[2] = temporalLogic->next;
					/*printf("----\n");
					printf("%p - %p - %p\n", pointersTransmitter[0], pointersTransmitter[1], pointersTransmitter[2]);
					printf("%p - %p - %p\n", pointersReceiver[0], pointersReceiver[1], pointersReceiver[2]);
					printf("%p - %p - %p\n", pointersReceiver[1]->prev, pointersReceiver[1], pointersReceiver[2]->next);
					printf("----\n");*/
					pointersTransmitter[1]->next = pointersReceiver[2];
					pointersTransmitter[1]->prev = pointersReceiver[0];
					if (pointersReceiver[0])
					{
						pointersReceiver[0]->next = pointersTransmitter[1];
					}
					if (pointersReceiver[2])
					{
						pointersReceiver[2]->prev = pointersTransmitter[1];
					}

					pointersReceiver[1]->next = pointersTransmitter[2];
					pointersReceiver[1]->prev = pointersTransmitter[0];
					if (pointersTransmitter[2])
					{
						pointersTransmitter[2]->prev = pointersReceiver[1];
					}
					if (pointersTransmitter[0])
					{
						pointersTransmitter[0]->next = pointersReceiver[1];
					}
					else
					{
						*deck = pointersReceiver[1];
					}
					temporal = pointersReceiver[1];
					/*
					if (pointersTransmitter[0])
						pointersTransmitter[0]->next = pointersReceiver[1];
					/*printf("----\n");
					printf("%p - %p - %p\n", pointersTransmitter[0], pointersTransmitter[1], pointersTransmitter[2]);
					printf("%p - %p - %p\n", pointersReceiver[0], pointersReceiver[1], pointersReceiver[2]);
					printf("%p - %p - %p\n", pointersReceiver[1]->prev, pointersReceiver[1], pointersReceiver[2]->next);
					printf("----\n");*/

					/*pointersTransmitter[1]->next = pointersReceiver[2];
					pointersReceiver[2]->prev = pointersTransmitter[1];
					pointersTransmitter[1]->prev = pointersReceiver[0];
					pointersReceiver[0]->next = pointersTransmitter[1];*/
					/*break;*/
					printf("before-Value-card=%s, before-kind-card=%d\n", temporalLogic->card->value, temporalLogic->card->kind);
				}
			}
			temporal = temporal->next;
			currentPosition++;
		}
		x++;
		currentPosition = 0;
		printf("---------\n");
		printf("---------\n");
		printf("%s - %d", (*deck)->card->value, (*deck)->card->kind);
		printf("---------\n");
		printf("---------\n");
	} while (x < 5);
	printf("((%d))",x);
}
