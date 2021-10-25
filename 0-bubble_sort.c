#include "sort.h"

/**
 * bubble_sort - algorithm to sort using bubble sort
 * @array: array with values
 * @size: size of array
 * Return: Without return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int val = 0;
	int temporalValue = 0;

	for (; j < size - 1; j++)
	{
		val = 0;
		for (i = 0; (i + 1) < (size - j); i++)
		{
			if (array[i] > array[i + 1])
			{
				val = 1;
				temporalValue = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temporalValue;
				print_array(array, size);
			}
		}
		if (!val)
			break;
	}
}
