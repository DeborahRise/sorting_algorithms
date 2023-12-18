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
 * bubble_sort - a bubble sort function for an array
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, status = 1;

	if (array == NULL || size < 2)
		return;

	while (status)
	{
		status = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				element_swap(array + i, array + i + 1);
				print_array(array, size);
				status = 1;
			}
		}
	}
}
