#include "sort.h"

/**
 * shell_sort - A function that sorts an array of integers in ascending
 *				order using Knuth sequence
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	/* Calculate the initial gap (Knuth sequence) */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Loop to perform Shell sort */
	while (gap > 0)
	{
		/* Element insertion for elements in the gap */
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			/* Shifting elements */
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3; /* Calculate the next gap */
	}
}
