#include "sort.h"

/**
 * merger - merge sub-arrays of an array or its sub-array.
 * @array: the array.
 * @lb: lower bound of the array or its sub-array.
 * @mid: middle.
 * @ub: upper bound.
 * @backup: array containing the sorted subarrays.
 */
void merger(int *array, size_t lb, size_t mid, size_t ub, int *backup)
{
	size_t i = lb, j = mid + 1, k;

	printf("Merging...\n[left]:");
	for (k = lb; k <= mid; k++)
	{
		printf(" %d", array[k]);
		if (k < mid)
			printf(",");
	}
	printf("\n[right]:");
	for (k = mid + 1; k <= ub; k++)
	{
		printf(" %d", array[k]);
		if (k < ub)
			printf(",");
	}
	for (k = lb; k <= ub; k++)
	{
		if (i <= mid && (j > ub || array[i] <= array[j]))
		{
			backup[k] = array[i];
			i++;
		}
		else
		{
			backup[k] = array[j];
			j++;
		}
	}
	printf("\n[Done]:");
	for (k = lb; k <= ub; k++)
	{
		array[k] = backup[k];
		printf(" %d", array[k]);
		if (k < ub)
			printf(",");
	}
	printf("\n");
}

/**
 * mergeSplit - recursively split an array into subarray and merge sorted.
 * @array: the array.
 * @lb: lower bound of an array or its sub-array.
 * @ub: upper bound of an array or its sub-array.
 * @backup: temp array to merge sorted sub-arrays.
 */
void mergeSplit(int *array, size_t lb, size_t ub, int *backup)
{
	size_t mid, lbub = lb + ub;

	if (ub <= lb)
		return;
	mid = lbub / 2;
	if (lbub % 2 == 0)
		mid -= 1;
	mergeSplit(array, lb, mid, backup);
	mergeSplit(array, mid + 1, ub, backup);
	merger(array, lb, mid, ub, backup);
}

/**
 * merge_sort - merge sort algorith implementation.
 * @array: array to sort.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *backup = NULL;
	size_t lb = 0, ub = size - 1;

	if (!array || size < 2)
		return;
	backup = calloc(size, sizeof(int));
	mergeSplit(array, lb, ub, backup);
	free(backup);
}
