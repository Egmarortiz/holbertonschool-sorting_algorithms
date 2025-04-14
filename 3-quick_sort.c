#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap_int - swaps two integers.
 * @a: pointer to first int.
 * @b: pointer to second int.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	if (a == b)
		return;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions array with Lomuto scheme.
 * @array: array of ints.
 * @low: start index.
 * @high: end index.
 * @size: total size of array.
 *
 * Return: pivot index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		swap_int(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - recursively sorts using quick sort.
 * @array: array of ints.
 * @low: start index.
 * @high: end index.
 * @size: total array size.
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array in ascending order using quick sort.
 * @array: array of ints.
 * @size: number of elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}

