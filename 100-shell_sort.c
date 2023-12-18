#include "sort.h"

/**
 * shell_sort - inplement shell sort algorith
 * @array: the array to sort.
 * @size: size of the array.
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap = 1, i, j;

	if (!array || size < 2)
		return;
	while (gap < size)
		gap = gap * 3 + 1;
	for (gap = gap / 3; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
