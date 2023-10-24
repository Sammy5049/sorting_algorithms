#include "sort.h"

/**
 * bubble_sort - function to sorts an array of
 * integers with bubble sort algo
 * @array: the array to sort
 * @size: size of the array.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
		return;

    for (i = 0; i < size; i++)
    {
        size_t flag_num = 0;
        size_t j;
        size_t temp;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
                flag_num += 1;
            }

        }
        if (flag_num == 0)
        {
            break;
        }
    }
    
}