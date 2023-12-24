#include "sort.h"

/**
 * swap - Swaps the values of two integers and prints the array.
 * @num1: The first integer to swap.
 * @num2: The seconde integer to swap.
 * @array: The array where the swap operation is performed.
 * @size: Size of @array.
 *
 * Return: Nothing.
 */
void swap(int *num1, int *num2, int *array, size_t size)
{
	int temp;

	if (*num1 != *num2)
	{
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
		print_array(array, size);
	}
}

/**
 * partition - Partitions the array around a pivot.
 * @array: The array to partition.
 * @l: The starting index of the partition.
 * @h: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot in the partitioned array.
 */
int partition(int *array, size_t l, size_t h, size_t size)
{
	int pivot, start_index, end_index;

	pivot = array[h];
	start_index = l;
	end_index = h - 1;

	while (start_index <= end_index)
	{
		while (start_index <= end_index && array[start_index] <= pivot)
			start_index++;

		while (start_index <= end_index && array[end_index] > pivot)
			end_index--;

		if (start_index < end_index)
			swap(&array[start_index], &array[end_index], array, size);
	}
	if (array[start_index] > pivot)
		swap(&array[start_index], &array[h], array, size);

	return (start_index);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array to sort.
 * @size: Size of @array.
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Recursively sorts the elements to the
 * left and right of the pivot.
 * @array: The array to sort.
 * @l: The starting index of the partition.
 * @h: The ending index of the partition.
 * @size: Size of @array.
 *
 * Return: Nothi.
 */
void quick_sort_helper(int *array, size_t l, size_t h, size_t size)
{
	if (l < h)
	{
		size_t pivot_index = partition(array, l, h, size);

		if (pivot_index != 0)
			quick_sort_helper(array, l, pivot_index - 1, size);
		if (pivot_index + 1 < size)
			quick_sort_helper(array, pivot_index + 1, h, size);
	}
}
