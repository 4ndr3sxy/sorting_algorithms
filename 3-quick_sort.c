#include "sort.h"

/**
 * partition - Partition an array with lomuto
 * @array: Array
 * @min: index min in array
 * @max: index max in array
 * @size: size of array
 * Return: index of pivote
 */
int partition(int *array, int min, int max, size_t size)
{
	int pivot = array[max], temporalValue = 0;
	int i = min - 1, j;

	for (j = min; j <= max; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temporalValue = array[i];
				array[i] = array[j];
				array[j] = temporalValue;
				print_array(array, size);
			}
		}
	}
	return (i);
}
/**
 * quick_sort_recursion - function to sort an array with recursion lomuto
 * @array: pointer to array
 * @min: index min in array
 * @max: index max in array
 * @size: Size of The Array
 * Return: without return
 */
void quick_sort_recursion(int *array, int min, int max, size_t size)
{
	int i;

	if (min < max)
	{
		i = partition(array, min, max, size);
		quick_sort_recursion(array, min, i - 1, size);
		quick_sort_recursion(array, i + 1, max, size);
	}
}
/**
 * quick_sort - Quick Sort using lomuto
 * @array: Array with values
 * @size: Size of Array
 * Return: Without return
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}
