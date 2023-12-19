#include <stdio.h>
#include "sort.h"
/**
 * selection_sort - performs the selection sort algorithm to sort
 * integers in an array
 * @array: array of integers
 * @size: size of array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
	int temp;

	if (array && size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			minIndex = i;

			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[minIndex])
				{
					minIndex = j;
				}
			}

			if (i != minIndex)
			{
				/* swap */
				temp = array[i];
				array[i] = array[minIndex];
				array[minIndex] = temp;

				/* print after every swap */
				print_array(array, size);
			}
		}
	}
}
