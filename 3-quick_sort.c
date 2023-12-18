#include "sort.h"

/**
 * swap - swap two elements of an array.
 * @array: array whose elements are to swapped.
 * @size: size of the array.
 * @i: index of first element.
 * @j: index of second element.
**/
void swap(int *array, int size, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * partition - partition a sorted element in a qsort implimentation.
 * @array: the array to sort.
 * @size: size of the array.
 * @lb: lower-bound of an unsorted partition.
 * @ub: upper-bound of the unsorted partition.
**/
void partition(int *array, int size, int lb, int ub)
{
	int piv, si = lb - 1, step = lb;

	if (!array || (ub <= lb))
		return;
	piv = array[ub];
	for (; step <= ub; step++)
	{
		if (array[step] < piv)
		{
			si++;
			if (array[step] != array[si])
				swap(array, size, si, step);
		}
	}
	if (si + 1 < ub)
		swap(array, size, si + 1, ub);
	partition(array, size, lb, si);
	partition(array, size, si + 2, ub);
}

/**
 * quick_sort - sort an array of integers using the qsort algorithm.
 * @array: the array to sort.
 * @size: the size of the array.
**/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	partition(array, size, 0, size - 1);
}
