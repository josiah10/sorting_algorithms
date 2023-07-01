#include "sort.h"
#include <stdlib.h>

/**
 * pow_10 - calculates a positive power of 10
 * @power: power of 10 to calculate
 *
 * Return: the corresponding power of 10
 */
unsigned int pow_10(unsigned int power)
{
	unsigned int i, result;

	result = 1;
	for (i = 0; i < power; i++)
		result *= 10;
	return (result);
}

/**
 * count_sort - sorts an array of integers in ascending order at a specific
 * digit location using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 * @digit: digit to sort by
 *
 * Return: 1 if there is a need to keep sorting, 0 if not
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int i, count[10] = {0};
	int *copy = NULL;
	size_t j, temp, total = 0;
	unsigned int dp1, dp2, sort = 0;

	dp2 = pow_10(digit - 1);
	dp1 = dp2 * 10;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] / dp1 != 0)
			sort = 1;
	}
	for (i = 0; i < 10 ; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] % dp1) / dp2] += 1;
	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[(copy[j] % dp1) / dp2]] = copy[j];
		count[(copy[j] % dp1) / dp2] += 1;
	}
	free(copy);
	return (sort);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 * the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; sort == 1; i++)
	{
		sort = count_sort(array, size, i);
		print_array(array, size);
	}
}
