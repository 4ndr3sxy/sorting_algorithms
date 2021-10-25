#include "sort.h"

/**
 * search_index - search an new index in array
 * @array: array with values
 * @index: initial index
 * @size: size of array
 * Return: new index or -1
 */
int search_index(int *array, int size, int index)
{
	int min = 0, newIndex = 0, i = 0;

	min = array[index];
	newIndex = index;
	for (i = index; i <= size - 1; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			newIndex = i;
		}
	}
	if (newIndex == index)
		return (-1);
	return (newIndex);
}

/**
 * selection_sort - algoritm that use the selection_sort
 * @array: array of integers
 * @size: size of array
 * Return: without return
 */
void selection_sort(int *array, size_t size)
{
	int i = 0, j = 0, temporalValue = 0;

	for (i = 0; i < (int)size; i++)
	{
		j = search_index(array, (int)size, i);
		if (j >= 0)
		{
			temporalValue = array[i];
			array[i] = array[j];
			array[j] = temporalValue;
			print_array(array, size);
		}
	}
}
