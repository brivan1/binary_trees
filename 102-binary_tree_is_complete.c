#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);


	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		exit(1);

	const binary_tree_t **temp = queue;
	*temp = tree;
	temp++;

	while (*queue != NULL)
	{
		const binary_tree_t *current = *queue;
		queue++;

		if (current->left != NULL)
		{
			*temp = current->left;
			temp++;
		}
		else if (current->right != NULL)
		{
			free(queue);
			return (0);
		}

		if (current->right != NULL)
		{
			*temp = current->right;
			temp++;
		}
		else
		{
			while (*queue != NULL)
			{
				if ((*queue)->left != NULL || (*queue)->right != NULL)
				{
					free(queue);
					return (0);
				}
				queue++;
			}
		}
	}

	free(queue);
	return (1);
}
