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
	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				/* swap */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		print_array(array, size);
	}
}
