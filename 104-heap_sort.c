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
 * helper_heap - a helper funtion for the heap sort.
 * @array: array of integers to be sorted
 * @sub_array: the sub_array
 * @super_node: super node
 * @size: size of the array
 */
void helper_heap(int *array, int sub_array, int super_node, size_t size)
{
	int max, down, up;

	max = super_node;
	down = super_node * 2 + 1;
	up = down + 1;

	if (down < sub_array && array[down] > array[max])
		max = down;
	if (up < sub_array && array[up] > array[max])
		max = up;
	if (max != super_node)
	{
		element_swap(array + max, array + super_node);
		print_array(array, size);
		helper_heap(array, sub_array, max, size);
	}
}


/**
 * heap_sort - Sorts in ascending order
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, n = (int)size;

	for (i = n / 2 - 1; i >= 0; i--)
		helper_heap(array, n, i, size);
	for (i = n - 1; i > 0; i--)
	{
		element_swap(array + 0, array + i);
		print_array(array, size);
		helper_heap(array, i, 0, size);
	}

}
