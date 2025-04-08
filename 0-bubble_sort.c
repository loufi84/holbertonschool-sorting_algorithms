#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of int in
 *				ascending order (bubble sort)
 *
 * @array: The array to sort
 * @size: Number of elements
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
