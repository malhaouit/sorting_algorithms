#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array to sort
 * @size: The size of @array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp, flag;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		flag = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
				flag = 1;
			}
		}

		if (flag)
		{
			temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
