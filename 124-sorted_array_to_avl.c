#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: A pointer to the first element of the sorted array
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size - 1));
}

/**
 * build_avl - Recursive helper function to build an AVL tree from a sorted array
 * @array: A pointer to the first element of the sorted array
 * @start: The starting index of the current subtree in the array
 * @end: The ending index of the current subtree in the array
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *build_avl(int *array, size_t start, size_t end)
{
	if (start > end)
		return (NULL);

	size_t mid = (start + end) / 2;

	avl_t *root = binary_tree_node(NULL, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = build_avl(array, start, mid - 1);
	root->right = build_avl(array, mid + 1, end);

	return (root);
}
