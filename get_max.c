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
