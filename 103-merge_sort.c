#include "sort.h"
#include <unistd.h>

/**
 * print_merge - print values of right and left
 * @array: array with values
 * @init: initial of index in array
 * @end: end of index in array
 * Return: without return
 */
void print_merge(int *array, int init, int end)
{
	while (init < end)
	{
		printf("%d%s", array[init], (init + 1 < end ? ", " : "\n"));
		init++;
	}
}

/**
 * top_down_merge - top-down implementation
 * @array: array with values
 * @copyArray: array temporal
 * @iInit: index initial of array
 * @iMiddle: index middle (iInit + iEnd) / 2
 * @iEnd: index end of array
 * Return: Without return
 */
void top_down_merge(int *array, int *copyArray, int iInit, int iMiddle, int iEnd)
{
	int i = iInit, j = iMiddle, k = 0;

	for (k = iInit; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || array[i] <= array[j]))
		{
			copyArray[k] = array[i];
			i++;
		}
		else
		{
			copyArray[k] = array[j];
			j++;
		}
	}
}

/**
 * top_down_split_merge - recursion to sort and print values of left and right
 * @array: array with values
 * @copyArray: array temporal
 * @iInit: index initial
 * @iEnd: index end
 * Return: Without return
 */
void top_down_split_merge(int *array, int *copyArray, int iInit, int iEnd)
{
	int iMiddle = 0;

	if (iEnd - iInit < 2)
	{
		return;
	}

	iMiddle = (iEnd + iInit) / 2;
	top_down_split_merge(copyArray, array, iInit, iMiddle);
	top_down_split_merge(copyArray, array, iMiddle, iEnd);
	printf("Merging...\n[left]: ");
	print_merge(array, iInit, iMiddle);
	printf("[right]: ");
	print_merge(array, iMiddle, iEnd);
	top_down_merge(copyArray, array, iInit, iMiddle, iEnd);
	printf("[Done]: ");
	print_merge(array, iInit, iEnd);
}

/**
 * merge_sort - Function init
 * @array; array with values
 * @size: size of array
 * Return: without return
 */
void merge_sort(int *array, size_t size)
{
	int *copyArray = NULL, i = 0;

	copyArray = malloc(sizeof(int) * size);
	if (!copyArray)
		return;
	for (; i < (int)size; i++)
	{
		copyArray[i] = array[i];
	}
	top_down_split_merge(array, copyArray, 0, size);
	free(copyArray);
}
