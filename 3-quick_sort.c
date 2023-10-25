#include "sort.h"


/**
 * swap_ints - Swap two ints in an array.
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
 * partition_sort - funct to partition the array
 * @array: array of unsorted ints
 * @lower: lower bound of the list
 * @upper: upper bound of the list
 * @size: size of the array
 * Return: position of the upper bound after iter
 */
int partition_sort(int *array, size_t size, int lower, int upper)
{
	int *pivot, above, below, left, right;
	left = lower;
	right = upper;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}



/**
 * quick_sort_recursive - funct to recusively call quick sort.
 * @array: array list to sort.
 * @lower: lower bound.
 * @upper: upper bound.
 * @size: size of array.
 */
void quick_sort_recursive(int *array, int lower, int upper,  size_t size)
{
	int position;

	if (lower < upper)
	{
		position = partition_sort(array, size, lower, upper);
		quick_sort_recursive(array, lower, position - 1, size);
		quick_sort_recursive(array, position + 1, upper, size);
	}
}

/**
 * quick_sort - funct to sort array list with quick sort.
 * @array: unsorted array.
 * @size: size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size  < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, size - 1, size);
}

