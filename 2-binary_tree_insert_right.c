#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 * @parent: pointer to the parent node
 * @value: value of the node to be inserted
 * Return: pointer to the inserted node
 *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *tmp;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL || parent == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	if (parent->right == NULL)
		parent->right = node;
	else
	{
		tmp = parent->right;
		parent->right = node;
		node->right = tmp;
		tmp->parent = node;
	}

	return (node);
}
