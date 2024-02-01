#include "binary_trees.h"

/**
 * bst_search - This searches for a value in a Binary Search Tree (BST)
 * @tree: A pointer to the root node of the BST to search
 * @value: The value to search for
 * Return: A pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);
	else if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (tree->right, value);
}
