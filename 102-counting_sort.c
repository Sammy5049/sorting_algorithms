#include "sort.h"

/**
 * get_maximum - function to get maximum val.
 * @array: Array of integers.
 * @size: Array size.
 * Return: Maximum int.
 */
int get_maximum(int *array, int size)
{
	int max, count;

	for (max = array[0], count = 1; count < size; count++)
	{
		if (array[count] > max)
			max = array[count];
	}

	return (max);
}

/**
 * counting_sort - Funct to Sort an array of integers with counting sort
 * @array: Array of integers.
 * @size: Array size.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, itr;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_maximum(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (itr = 0; itr < (max + 1); itr++)
		count[itr] = 0;
	for (itr = 0; itr < (int)size; itr++)
		count[array[itr]] += 1;
	for (itr = 0; itr < (max + 1); itr++)
		count[itr] += count[itr - 1];
	print_array(count, max + 1);

	for (itr = 0; itr < (int)size; itr++)
	{
		sorted[count[array[itr]] - 1] = array[itr];
		count[array[itr]] -= 1;
	}

	for (itr = 0; itr < (int)size; itr++)
		array[itr] = sorted[itr];

	free(sorted);
	free(count);
}