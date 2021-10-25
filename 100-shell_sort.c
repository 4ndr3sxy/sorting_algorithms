#include "sort.h"

/**
 * shell_sort - Algorithm sort
 * @array: array of values to sort
 * @size: size of array
 * Return: Without return
 */
void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, k = 0, knuth = 1;

	if (!array || !size || size < 2)
		return;
	while (knuth <= (int)(size - 1) / 3)
		knuth = (3 * knuth) + 1;
	while (knuth > 0)
	{
		for (i = knuth; i < (int)size; i++)
		{
			k = array[i];
			for (j = i - knuth; j >= 0; j = j - knuth)
			{
				if (k < array[j])
					array[j + knuth] = array[j];
				else
					break;
			}
			array[j + knuth] = k;
		}
		knuth = knuth / 3;
		print_array(array, size);
	}
}
