/*
 * File: 106-bitonic_sort.c
 * Auth: damilola and mayor
 */

#include "sort.h"

/**
 * swap_ints - funct to Swap two integers in an array.
 * @a: first integer.
 * @b: second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * merge_bito - Sort bitonic sequence.
 * @array: Array of integers.
 * @size: size of array.
 * @start: start index of the sequence.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort through.
 */
void merge_bito(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t count, gap = seq / 2;

	if (seq > 1)
	{
		for (count = start; count < start + gap; count++)
		{
			if ((flow == UP && array[count] > array[count + gap]) ||
					(flow == DOWN && array[count] < array[count + gap]))
				swap_ints(array + count, array + count + gap);
		}
		merge_bito(array, size, start, gap, flow);
		merge_bito(array, size, start + gap, gap, flow);
	}
}

/**
 * sequence_bito - Convert an array into bitonic sequence.
 * @array: Array of integers.
 * @size: size of array.
 * @start: start index of the sequence.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort through.
 */
void sequence_bito(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t brk = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		sequence_bito(array, size, start, brk, UP);
		sequence_bito(array, size, start + brk, brk, DOWN);
		merge_bito(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers using bitonic sort
 * @array: Array of integers.
 * @size: size of array.
 *
 * Description: Prints array after every swap. works for
 * size = 2^k where k >= 0 only.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sequence_bito(array, size, 0, size, UP);
}
