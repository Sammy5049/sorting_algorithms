#include "sort.h"

/**
 * sub_array_merge - funct to Sort subarray of integers.
 * @sub_array: subarray of array of integers to be sorted.
 * @buffer: memory space to store sorted result.
 * @fwd: front index of subarray.
 * @bck: back index of subarray.
 * @mid: The middle index of the array.
 */
void sub_array_merge(int *sub_array, int *buffer, size_t fwd, size_t mid,
		size_t bck)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + fwd, mid - fwd);

	printf("[right]: ");
	print_array(sub_array + mid, bck - mid);

	for (i = fwd, j = mid; i < mid && j < bck; k++)
		buffer[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < mid; i++)
		buffer[k++] = sub_array[i];
	for (; j < bck; j++)
		buffer[k++] = sub_array[j];
	for (i = fwd, k = 0; i < bck; i++)
		sub_array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(sub_array + fwd, bck - fwd);
}

/**
 * merge_sort_rec - merge sort algorithm with recursion.
 * @sub_array: subarray of array of integers to be sorted.
 * @buffer: memory space to store sorted result.
 * @fwd: front index of subarray.
 * @bck: back index of subarray.
 */
void merge_sort_rec(int *sub_array, int *buffer, size_t fwd, size_t bck)
{
	size_t mid;

	if (bck - fwd > 1)
	{
		mid = fwd + (bck - fwd) / 2;
		merge_sort_rec(sub_array, buffer, fwd, mid);
		merge_sort_rec(sub_array, buffer, mid, bck);
		sub_array_merge(sub_array, buffer, fwd, mid, bck);
	}
}

/**
 * merge_sort - funct to Sort an array with merge sort
 * @array: Array of integers.
 * @size: Array size.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;
	if (array == NULL || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;
	merge_sort_rec(array, buffer, 0, size);
	free(buffer);
}