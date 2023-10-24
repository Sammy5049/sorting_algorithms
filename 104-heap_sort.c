#include "sort.h"

/**
 * make_max_heap - make heap from binary tree.
 * @array: Array of integers of binary tree.
 * @size: size of array/tree.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */
void make_max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large, temp;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
        temp = array[root];
        array[root] = array[large];
        array[large] = temp;
		print_array(array, size);
		make_max_heap(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array with heap sort
 * @array: Array of integers.
 * @size: size of array.
 */
void heap_sort(int *array, size_t size)
{
	int count, temp;

	if (array == NULL || size < 2)
		return;

	for (count = (size / 2) - 1; count >= 0; count--)
		make_max_heap(array, size, size, count);

	for (count = size - 1; count > 0; count--)
	{
        temp = array[0];
        array[0] = array[count];
        array[count] = temp;
		print_array(array, size);
		make_max_heap(array, size, count, 0);
	}
}