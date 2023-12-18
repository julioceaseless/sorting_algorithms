#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - implements the bubble sort algorithm
 * @array: an array of integers to be sorted
 * @size: size of the array
 */


void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped, temp;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* check for swap */

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swap eligible numbers */
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;

				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}

