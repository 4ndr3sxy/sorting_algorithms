#include "sort.h"

/**
 * selection_sort - algoritm that use the selection_sort
 * @array: array of integers
 * @size: size of array
 * Return: without return
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int indexValue = 0, valueSelection = 0, validateSwap = 0;
	int temporalValue = 0;

	for (; i < size; i++)
	{
		validateSwap = 0;
		valueSelection = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < valueSelection)
			{
				validateSwap = 1;
				valueSelection = array[j];
				indexValue = j;
			}
		}
		if (validateSwap)
		{
			temporalValue = array[i];
			array[i] = valueSelection;
			array[indexValue] = temporalValue;
			print_array(array, size);
		}
		else
			break;
	}
}
