#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @array: the array
 * @i: going to be swapped
 * @jMin: going to be swapped
**/

void swap(int *array, unsigned int i, unsigned int jMin)
{
	int temp;

	temp = array[i];
	array[i] = array[jMin];
	array[jMin] = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order,
 * using the Selection sort algorithm
 * @array: the array
 * @size: size of the array
**/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, jMin;

	for (i = 0; i < size; i++)
	{
		jMin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}

		if (jMin != i)
		{
			swap(array, i, jMin);
			print_array(array, size);
		}
	}
}
