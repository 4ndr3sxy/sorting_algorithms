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
	int valueSelection = 0, temporalValue = 0;
	int validateSwap = 0;

	for (; i < size; i++)
	{
		validateSwap = 0;
		valueSelection = array[i];
		for (j = i; j < size; j++)
		{
			/*printf("%d > %d ", valueSelection, array[j]);*/
			if (valueSelection > array[j])
			{
				/*printf("YES");*/
				validateSwap = 1;
				temporalValue = array[j];
				array[j] = valueSelection;
				valueSelection = temporalValue;
				array[i] = valueSelection;
			}
		}
		if (validateSwap)
			print_array(array, size);
		else
			break;
	}
}
