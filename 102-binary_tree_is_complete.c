#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *));

	if (queue == NULL)
		return (0);

	int flag1 = 0, flag2 = 0;

	queue[0] = (binary_tree_t *)tree;
	int front = 0, rear = 1;

	while (front < rear)
	{

	binary_tree_t *current = queue[front++];

	if (current->left != NULL)
	{

	if (flag1)
	{
		free(queue);
		return (0);
	}
	queue = realloc(queue, (rear + 1) * sizeof(binary_tree_t *));
	queue[rear++] = current->left;
	}
	else
	{
		flag1 = 1;
	if (current->right != NULL)
	{

	if (flag1)
	{
		free(queue);
		return (0);
	}
	queue = realloc(queue, (rear + 1) * sizeof(binary_tree_t *));
	queue[rear++] = current->right;
	}
	else
	{
		flag1 = 1;
	}
	}

	free(queue);
	return (1);
}
