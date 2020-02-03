#include "sort.h"

/**
 * selection_sort - Sorts an array using the selection sort algorithm.
 *
 * @array: array to sort.
 * @size: size of the array.
 *
 * Description - This program traverses an array and compares the selected
 *               element with the rest of the array, if it finds a lower value
 *               than the selected one, it swapes their positions and continues
 *               with the new element. It then continues with the second
 *               element in the array until it finishes.
 *
 * Return: Nothing (void).
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t index, jndex, lower_pos;
	int tmp, menor, change;

	if (size < 2)
		return;

	for (index = 0; index < size - 1; index++)
	{
		menor = array[index];
		change = 0;

		for (jndex = index + 1; jndex < size; jndex++)
		{
			if (menor > array[jndex])
			{
				change++;
				menor = array[jndex];
				lower_pos = jndex;
			}
		}
		if (change != 0)
		{
			tmp = array[index];
			array[index] = array[lower_pos];
			array[lower_pos] = tmp;
			print_array(array, size);
		}
		else
			continue;
	}
}
