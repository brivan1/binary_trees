#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_bst - This builds a Binary Search Tree (BST) from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	bst_t *root = NULL;

	for (size_t i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
