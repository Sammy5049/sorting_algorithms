#include "sort.h"

/**
 * swap_ints - Swap two int.
 * @a: 1st int.
 * @b: 2nd int.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sort an array with selection sort algo
 * @array: Array containing unsorted ints
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *smallest;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = array + i;

		for (j = i + 1; j < size; j++)
			smallest = (array[j] < *smallest) ? (array + j) : smallest;

		if (smallest != (array + i))
		{
			swap_ints(array + i, smallest);
			print_array(array, size);
		}
	}
}

