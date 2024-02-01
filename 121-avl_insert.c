#include "binary_trees.h"

/**
 * avl_insert - This inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to insert in the AVL tree
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	*tree = avl_insert_recursive(*tree, value);

	return *tree;
}

/**
 * avl_insert_recursive - Shows recursive helper function to insert a value in AVL Tree
 * @node: A pointer to the current node
 * @value: The value to insert
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t *node, int value)
{
	if (node == NULL)
		return (binary_tree_node(NULL, value));

	if (value < node->n)
		node->left = avl_insert_recursive(node->left, value);
	else if (value > node->n)
		node->right = avl_insert_recursive(node->right, value);
	else
		return (NULL);


	node->height = 1 + max(avl_height(node->left), avl_height(node->right));


	return (avl_balance(node));
}

/**
 * avl_height - This computes the height of an AVL tree
 * @node: A pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
int avl_height(const avl_t *node)
{
	if (node == NULL)
		return (0);

	return (node->height);
}

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * avl_balance - Performs rotations to restore balance in an AVL Tree
 * @node: A pointer to the current node
 *
 * Return: A pointer to the balanced node
 */
avl_t *avl_balance(avl_t *node)
{
	int (balance);

	if (node == NULL)
		return (NULL);

	balance = avl_height(node->left) - avl_height(node->right);


	if (balance > 1 && node->left != NULL && node->left->n > value)
		return (avl_rotate_right(node));


	if (balance < -1 && node->right != NULL && node->right->n < value)
		return (avl_rotate_left(node));


	if (balance > 1 && node->left != NULL && node->left->n < value)
	{
		node->left = avl_rotate_left(node->left);
		return (avl_rotate_right(node));
	}


	if (balance < -1 && node->right != NULL && node->right->n > value)
	{
		node->right = avl_rotate_right(node->right);
		return (avl_rotate_left(node));
	}

	return (node);
}

/**
 * avl_rotate_left - Performs a left rotation in an AVL Tree
 * @y: A pointer to the current node
 *
 * Return: A pointer to the new root node after rotation
 */
avl_t *avl_rotate_left(avl_t *y)
{
	avl_t *x = y->right;
	avl_t *T2 = x->left;

	x->left = y;
	y->right = T2;

	y->right = max(avl_right(y->left), avl_right(y->right)) + 1;
	x->right = max(avl_right(x->left), avl_right(x->right)) + 1;

	return (x);
}

/**
 * avl_rotate_right - Performs a right rotation in an AVL Tree
 * @x: A pointer to the current node
 *
 * Return: A pointer to the new root node after rotation
 */
avl_t *avl_rotate_right(avl_t *x)
{
	avl_t *y = x->left;
	avl_t *T2 = y->right;

	y->right = x;
	x->left = T2;

	x->right = max(avl_right(x->left), avl_right(x->right)) + 1;
	y->right = max(avl_right(y->left), avl_right(y->right)) + 1;

	return (y);
}
