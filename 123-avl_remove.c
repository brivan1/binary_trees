#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL Tree
 * @root: A pointer to the root node of the AVL tree
 * @value: The value to remove from the AVL tree
 *
 * Return: A pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	root = avl_remove_recursive(root, value);

	return (root);
}

/**
 * avl_remove_recursive - Recursive helper function to remove
 * a value in AVL Tree
 * @node: A pointer to the current node
 * @value: The value to remove
 *
 * Return: A pointer to the new root node after removing the value
 */
avl_t *avl_remove_recursive(avl_t *node, int value)
{
	if (node == NULL)
		return (NULL);

	if (value < node->n)
		node->left = avl_remove_recursive(node->left, value);
	else if (value > node->n)
		node->right = avl_remove_recursive(node->right, value);
	else
	{
		if (node->left == NULL || node->right == NULL)
		{
			avl_t *temp = node->left ? node->left : node->right;

	if (temp == NULL)
	{
		temp = node;
		node = NULL;
	}
	else
		*node = *temp;
	free(temp);
		}
		else
		{
			avl_t *temp = avl_find_min(node->right);

			node->n = temp->n;
			node->right = avl_remove_recursive(node->right, temp->n);
		}
	}

	if (node == NULL)
		return (node);

	node->right = 1 + fmax(avl_height(node->left), avl_height(node->right));


	return (avl_balance(node));
}

/**
 * avl_find_min - Finds the node with the minimum value in an AVL tree
 * @node: A pointer to the root node of the tree
 *
 * Return: A pointer to the node with the minimum value
 */
avl_t *avl_find_min(avl_t *node)
{
	while (node->left != NULL)
	node = node->left;
	return (node);
}
