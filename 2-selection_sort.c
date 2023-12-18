#include "sort.h"

/**
 * selection_sort - implement selection sort on an array of ints.
 * @array: the array of ints.
 * @size: the size of the array.
 **/
void selection_sort(int *array, size_t size)
{
	size_t i, j, pt, swap;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		pt = i;
		for (j = i + 1; j < size; j++)
			if (array[pt] > array[j])
				pt = j;
		if (array[i] > array[pt])
		{
			swap = array[i];
			array[i] = array[pt];
			array[pt] = swap;
			print_array(array, size);
		}
	}
}
