#include "sort.h"


/**
 * partition_sort - funct to partition the array
 * @array: array of unsorted ints
 * @lower: lower bound of the list
 * @upper: upper bound of the list
 * @size: size of the array
 * Return: position of the upper bound after iter
 */
int partition_sort(int *array, int lower, int upper, size_t size)
{
	int pivot, temp;
	size_t start = lower, end = upper;

	pivot = array[lower];

	if (array == NULL || size < 2)
		return (1);

	while (start < end)
	{
		while (array[start] <= pivot)
		{
			start++;
		}
		while (array[end] > pivot)
		{
			end--;
		}

		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
		}

	}
	temp = array[lower];
	array[lower] = array[end];
	array[end] = temp;
	print_array(array, size);

	return (end);
}
/**
 * quick_sort_recursive - funct to recusively call quick sort.
 * @array: array list to sort.
 * @lower: lower bound.
 * @upper: upper bound.
 * @size: size of array.
 */
void quick_sort_recursive(int *array, size_t lower, size_t upper,  size_t size)
{
	int position;

	if (lower < upper)
	{
		position = partition_sort(array, lower, upper, size);
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

