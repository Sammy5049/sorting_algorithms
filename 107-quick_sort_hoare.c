#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: first int.
 * @b: second int.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: start indx of the subset.
 * @right: end indx of the subset.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int piv, upbd, lowbd;

	piv = array[right];
	for (upbd = left - 1, lowbd = right + 1; upbd < lowbd;)
	{
		do
		{
			upbd++;
		} while (array[upbd] < piv);
		do
		{
			lowbd--;
		} while (array[lowbd] > piv);

		if (upbd < lowbd)
		{
			swap_ints(array + upbd, array + lowbd);
			print_array(array, size);
		}
	}

	return (upbd);
}

/**
 * hoare_sorting - quicksort algorithm with recursion.
 * @array: Array of integers.
 * @size: size of array.
 * @left: beginning indx of the array.
 * @right: ending indx of the array.
 */
void hoare_sorting(int *array, size_t size, int left, int right)
{
	int div;

	if (right - left > 0)
	{
		div = hoare_partition(array, size, left, right);
		hoare_sorting(array, size, left, div - 1);
		hoare_sorting(array, size, div, right);
	}
}

/**
 * quick_sort_hoare - Sort an array with quick sort hoare
 * @array: Array of integers.
 * @size: size of array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sorting(array, size, 0, size - 1);
}
