#include "binary_trees.h"

/**
 * array_to_avl - This builds an AVL tree from an array
 * @array: Pointing to the first element of the array to be converted
 * @size: Number of elements in @array
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
