#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Shows recursive helper function to check if a binary tree is AVL
 * @node: A pointer to the current node
 * @min: The minimum valid value for the current node
 * @max: The maximum valid value for the current node
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	int left_height = binary_tree_height(node->left);
	int right_height = binary_tree_height(node->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_avl_helper(node->left, min, node->n) &&
	is_avl_helper(node->right, node->n, max));
}

/**
 * binary_tree_height - This computes the height of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return 1 + (left_height > right_height ? left_height : right_height);
}
