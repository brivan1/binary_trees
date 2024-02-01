#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: A double pointer to the root node of the BST
 * @value: The value to insert in the tree
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	return (insert_recursive(tree, value));
}

/**
 * insert_recursive - Shows a recursive helper function to insert a value in a BST
 * @tree: A double pointer to the current node
 * @value: The value to insert
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *insert_recursive(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		return (insert_recursive(&(*tree)->left, value));

	if (value > (*tree)->n)
		return (insert_recursive(&(*tree)->right, value));

	return (NULL);
}
