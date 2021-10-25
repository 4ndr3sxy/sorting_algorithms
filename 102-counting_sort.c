#include "sort.h"
#include <unistd.h>

/**
 * create_malloc - function to create mallocs
 * @size: size to malloc
 * Return: pointer to malloc
 */
int *create_malloc(int size)
{
	int *newMalloc = malloc(sizeof(int) * size);

	if (!newMalloc)
		return (NULL);
	return (newMalloc);
}

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

	for (i = 0; i < (int)size; i++)
		if (array[i] > maxValueArray)
			maxValueArray = array[i];
	maxValueArray++;
	new = create_malloc(maxValueArray);

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
	copyArray = create_malloc((int)size + 1);
	for (i = 0; i < (int)size; i++)
	{
		valueIndex = array[i];
		valueIndexTwo = new[valueIndex];
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
