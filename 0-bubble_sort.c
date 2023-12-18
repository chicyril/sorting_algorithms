#include "sort.h"
/**
 * bubble_sort - sort an array of integers using bubble-sort.
 * @array: the array of integers to sort.
 * @size: the size of the array.
 **/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	bool swapped = true;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		if (!swapped)
			return;
	}
}
