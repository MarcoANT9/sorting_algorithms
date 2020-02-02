#ifndef SORT_H
#define SORT_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/

/** Nothing :( */

/**========================================================================*/
/**-STRUCTURES-& DEFINITIONS-----------------------------------------------*/
/**========================================================================*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** Define size_t */
typedef unsigned long size_t;

/**========================================================================*/
/**-FUNCTIONS--------------------------------------------------------------*/
/**========================================================================*/

/** Support Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/** 0. Bubble Sorting */
void bubble_sort(int *array, size_t size);

/** 1. Insertion Sorting */
void insertion_sort_list(listint_t **list);

/** 2. Selection Sorting */
void selection_sort(int *array, size_t size);

/** 3. Quick Sorting */
void quick_sort(int *array, size_t size);

#endif
