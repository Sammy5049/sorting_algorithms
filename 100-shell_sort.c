#include "sort.h"

/**
 * shell_sort - sorting array with shell sort.
 * @array: array to be sort.
 * @size: size of array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				temp = array[j];
                array[j] = array[j - gap];
                array[j - gap] = temp;
				j -= gap;
			}
		}
		print_array(array, size);
	}
}