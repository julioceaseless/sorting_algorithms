#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap - Swap two int elements in an array
 * @int_a: pointer to first int
 * @int_b: pointer to second int
 */
void swap(int *int_a, int *int_b)
{
	int tmp;

	tmp = *int_a;
	*int_a = *int_b;
	*int_b = tmp;
}

/**
 * lomuto_partition - implement the lomuto partition scheme
 * to sort integers in the array
 * @array: array of integers
 * @size: array size
 * @lb: lower bound(starting index of array)
 * @ub: upper bound (ending index of array)
 *
 * Return: position of the start of the final partition index
 */
int lomuto_partition(int *array, size_t size, int lb, int ub)
{
	int *pivot;
	int end, start;

	pivot = &array[ub];
	end = lb;

	for (start = lb; start < ub; start++)
	{
		if (array[start] < *pivot)
		{
			if (end < start)
			{
				swap(&array[start], &array[end]);
				print_array(array, size);
			}
			end++;
		}
	}

	if (array[end] > *pivot)
	{
		swap(&array[end], pivot);
		print_array(array, size);
	}

	return (end);
}

/**
 * quicksort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: size of array
 * @lb: starting index of the array partition
 * @ub: ending index of the array partition
 *
 */
void quicksort(int *array, size_t size, int lb, int ub)
{
	int pos;

	if (ub > lb)
	{
		pos = lomuto_partition(array, size, lb, ub);
		quicksort(array, size, lb, pos - 1);
		quicksort(array, size, pos + 1, ub);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the quicksort algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Description: This is the wrapped function that calls the
 * quicksort algorithm if the array is not empty
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		quicksort(array, size, 0, size - 1);
	}
}
