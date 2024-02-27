#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm (LSD approach)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
size_t i;
int max, exp;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size);
        print_array(array, size);
    }
}
