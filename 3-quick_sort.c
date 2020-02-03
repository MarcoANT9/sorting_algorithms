#include "sort.h"

/**
 * partition - Takes care of the partition of the sub-arrays.
 *
 * @array: Array to swap values.
 * @low: Lower index.
 * @high: Higher index.
 * @size: Size of the array.
 *
 * Return: Index of the pivot value (Int).
 */

int partition(int *array, int low, int high, size_t size)
{
	int index, jndex;
	int tmp, pivot;

	pivot = array[high];
	index = low;
	for (jndex = index; jndex < high; jndex++)
	{
		if (array[jndex] <= pivot)
		{
			if (index != jndex)
			{
				tmp = array[jndex];
				array[jndex] = array[index];
				array[index] = tmp;
				print_array(array, size);
			}
			index++;
		}
	}
	tmp = array[index];
	array[index] = array[high];
	array[high] = tmp;
	print_array(array, size);
	return (index);
}

/**
 * squick - Recalls itself to organize the data.
 *
 * @array: Array to swap values.
 * @low: Lower index.
 * @high: Higher index.
 * @size: Size of the array.
 *
 * Return: Nothing (void).
 */


void squick(int *array, int low, int high, size_t size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		squick(array, low, pivot - 1, size);
		squick(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array using the quicksort algorithm.
 *
 * @array: array to sort.
 * @size: size of the array.
 *
 * Description - This program selects a pivot and puts it in its correct
 *               position, then it parts the list in sublists and finds
 *               and positions its pivot and recursevly does the same until
 *               the list is organized.
 *
 * Return: Nothing (void).
 *
 */
void quick_sort(int *array, size_t size)
{
	squick(array, 0, size - 1, size);
}
