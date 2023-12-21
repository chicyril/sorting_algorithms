#include "sort.h"

/**
 * counting_sort - counting sort algorithm sort.
 * @array: the array to sort.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, k = 0;
	int *countarr = NULL, *outarr = NULL;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > (int)k)
			k = array[i];
	countarr = calloc(k + 1, sizeof(int));
	outarr = malloc(sizeof(int) * size);
	if (!countarr || !outarr)
	{
		free(countarr);
		free(outarr);
		printf("Error Creating array.");
		return;
	}
	for (i = 0; i < size; i++)
		++countarr[array[i]];
	for (i = 1; i <= k; i++)
		countarr[i] = countarr[i - 1] + countarr[i];
	print_array(countarr, k + 1);
	for (i = size - 1; (int)i >= 0; i--)
		outarr[--(countarr[array[i]])] = array[i];
	for (i = 0; i < size; i++)
		array[i] = outarr[i];
	free(countarr);
	free(outarr);
}
