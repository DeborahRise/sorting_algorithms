#include "sort.h"
#include <stddef.h>

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
 * shell_sort - an algorithm that sorts an array of ints in ascending order
 * It uses a gap method, and swaps numbers accordingly, from opposite
 * sides of the gap.
 * @array: The array to be sorted
 * @size: size of the array is used in determining the gap. This is
 * usually divided by 3, using the knuth method
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t a, b, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap <= (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			for (b = a; b >= gap && array[b - gap] > array[b]; b -= gap)
			{
				element_swap(array + b, array + (b - gap));
			}
		}
		print_array(array, size);

	}
}
