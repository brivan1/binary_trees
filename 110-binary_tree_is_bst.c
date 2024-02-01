#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - Helper function to check if a binary tree is a valid BST
 * @tree: A pointer to the current node
 * @min: The minimum valid value for the current node
 * @max: The maximum valid value for the current node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}
