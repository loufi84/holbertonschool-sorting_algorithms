#include "sort.h"

/**
 * swap - A function that swap 2 integers
 *
 * @a: First integer
 * @b: Second integer
 */

void swap(int *a, int *b)
{
	int tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * lomuto - A function that finds the pivot point
 *
 * @array: The array to treat
 * @size:The size of the array
 * @low: The low point
 * @high: The high point
 *
 * Return: The Lomuto point
 */

int lomuto(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort_rec - A function to sort recursively an array of int
 *
 * @array: A pointer to the first element of the array
 * @size: The size of the array
 * @low: The low point
 * @high: The high point
 */

void quicksort_rec(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto(array, size, low, high);
		quicksort_rec(array, size, low, pivot_index - 1);
		quicksort_rec(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - A function that sorts an array of integers
 *				in ascending order usig the quick sort algorithm
 *
 * @array: A ponter to the first element of the array to sort
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_rec(array, size, 0, size - 1);
}
