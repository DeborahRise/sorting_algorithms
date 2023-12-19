#include "sort.h"

/**
 * selection_sort - using the selection_sort algorithm
 * for sorting
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *small_num;

	for (i = 0;  i < size - 1; i++)
	{
		small_num = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *small_num)
				small_num = (array + j);
		}
		if ((array + i) != small_num)
		{
			element_swap(array + i, small_num);
			print_array(array, size);
		}
	}
}

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
