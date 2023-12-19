#include "sort.h"

/**
 * element_swap - swap 2 elements
 * @a: 1st element
 * @b: element to be swapped with
 * Return: nothing
 */

void element_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * partition - the algorithm that helps with divide and conquer
 * technique
 * @array: the array to be sorted
 * @start: the first element to be sorted
 * @end: the last element to be reached during the quick sort
 * @size: the size of the array
 * Return: the index for the next pivot.
 */

int partition(int *array, int start, int end, size_t size)
{
	int i, j;
	int pivot = array[end];

	i = start - 1;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				element_swap(array + i, array + j);
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[i] != array[end])
	{
		element_swap(array + i, array + end);
		print_array(array, size);
	}

	return (i);
}


/**
 * quicky - the algorithm that helps with divide and conquer
 * technique
 * @array: the array to be sorted
 * @start: the first element to be sorted
 * @end: the last element to be reached during the quick sort
 * @size: the size of the array
 * Return: the index for the next pivot.
 */


void quicky(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;

	pivot = partition(array, start, end, size);
	quicky(array, start, pivot - 1, size);
	quicky(array, pivot + 1, end, size);
}


/**
 * quick_sort - the algorithm that helps with divide and conquer
 * technique
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: the index for the next pivot.
 */
void quick_sort(int *array, size_t size)
{
	quicky(array, 0, (int)size - 1, size);
}
