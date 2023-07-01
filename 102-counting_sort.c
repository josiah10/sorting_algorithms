#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count = NULL, *copy = NULL;
	size_t j, temp, total = 0;


	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (j = 0, max = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(copy);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]] += 1;
	for (i = 0; i <= max; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[copy[j]]] = copy[j];
		count[copy[j]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(copy);
}
