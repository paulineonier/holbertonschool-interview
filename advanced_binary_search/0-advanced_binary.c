#include <stdio.h>
#include "search_algos.h"

/**
 * recursive_search - Searches recursively for a value in a sorted array
 *                    of integers to find the first occurrence.
 * @array: Pointer to the first element of the array/subarray.
 * @left: The starting index of the current subarray.
 * @right: The ending index of the current subarray.
 * @value: The value to search for.
 *
 * Return: The index where value is located, or -1 if not found.
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t i, mid;

	if (left > right)
		return (-1);

	/* Print current subarray */
	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");

	/* Base case: single element remaining */
	if (left == right)
	{
		if (array[left] == value)
			return ((int)left);
		return (-1);
	}

	mid = left + (right - left) / 2;

	/* If value is at mid, search left including mid (first occurrence) */
	if (array[mid] >= value)
		return (recursive_search(array, left, mid, value));

	/* Otherwise search right sub-array */
	return (recursive_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: Index where value is located, or -1 if array is NULL or not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
