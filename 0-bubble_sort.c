#include "sort.h"

/**
 * bubble_sort - Sorts an array with the bubble sort methodology.
 *
 * @array: Array of number to sort.
 * @size: Size of the array to sort.
 *
 *
 * Description - This methodology, traverses an array and look at the data
 *               two by two looking for the greather one, and swaps places
 *               when necesary. This function returns nothing.
 *
 *
 * Return: Nothing (void).
 *
 */
void bubble_sort(int *array, size_t size)
{
	int _sw = 1, tmp;
	size_t index;

	if (size < 2)
		return;
	while (_sw != 0)
	{
		_sw = 0;
		for (index = 0; index < size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				tmp = array[index + 1];
				array[index + 1] = array[index];
				array[index] = tmp;
				_sw++;
				print_array(array, size);
			}
		}

	}

}
