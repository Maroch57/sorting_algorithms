#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: The array to be sorted
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc((left_size + right_size) * sizeof(int));

    if (temp == NULL)
        return;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            temp[k] = left[i];
            i++;
        }
        else
        {
            temp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        temp[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        temp[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < left_size + right_size; i++)
        array[i] = temp[i];

    free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm (top-down approach)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, left_size, right_size;
	int *left, *right;
    if (array == NULL || size < 2)
        return;

    mid = size / 2;
    left_size = mid;
    right_size = size - mid;

    left = array;
    right = array + mid;

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    merge(array, left, left_size, right, right_size);

    printf("[Done]: ");
    print_array(array, size);
}
