#include "sort.h"

/**
 * swap - swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t end, root, child;

	if (array == NULL || size < 2)
		return;
	end = size - 1;
	for (root = (size - 1) / 2; ; root--)
	{
		while (root * 2 + 1 <= end)
		{
			child = root * 2 + 1;
			if (child < end && array[child] < array[child + 1])
				child++;
			if (array[root] < array[child])
			{
				swap(&array[root], &array[child]);
				print_array(array, size);
				root = child;
			}
			else
				break;
		}
		if (root == 0)
			break;
	}
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		root = 0;
		while (root * 2 + 1 <= end)
		{
			child = root * 2 + 1;
			if (child < end && array[child] < array[child + 1])
				child++;
			if (array[root] < array[child])
			{
				swap(&array[root], &array[child]);
				print_array(array, size);
				root = child;
			}
			else
				break;
		}
	}
}
