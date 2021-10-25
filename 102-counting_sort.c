#include "sort.h"
#include <unistd.h>

/**
 * counting_sort - Algorithm sort
 * @array: array with values
 * @size: size of array
 * Return: Without return
 */
void counting_sort(int *array, size_t size)
{
	int maxValueArray = 0, i = 0, valueIndex = 0, valueIndexTwo = 0;
	int *copyArray = NULL, *new = NULL;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > maxValueArray)
			maxValueArray = array[i];
	maxValueArray++;
	new = malloc(sizeof(int) * maxValueArray);
	if (!new)
		return;

	for (i = 0; i < maxValueArray; i++)
		new[i] = 0;
	for (i = 0; i < maxValueArray; i++)
		if (i < (int)size)
		{
			valueIndex = array[i];
			new[valueIndex] += 1;
		}
	for (i = 0; i + 1 < maxValueArray; i++)
		new[i + 1] = new[i + 1] + new[i];
	for (i = 0; i < maxValueArray; i++)
		printf("%d%s", new[i], (i + 1 == maxValueArray ? "\n" : ", "));
	copyArray = malloc(sizeof(int) * size + 1);
	if (!copyArray)
		return;
	for (i = 0; i < (int)size; i++)
	{
		valueIndex = array[i], valueIndexTwo = new[valueIndex];
		copyArray[valueIndexTwo - 1] = valueIndex;
		new[valueIndex] = --valueIndexTwo;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = copyArray[i];
	}
	free(new);
	free(copyArray);
}
