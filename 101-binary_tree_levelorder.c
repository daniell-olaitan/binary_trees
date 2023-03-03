#include "binary_trees.h"

void enque(queue_t **h, const binary_tree_t *n);
binary_tree_t *deque(queue_t **h);

/**
 * binary_tree_levelorder - goes through a
 * binary tree using levelorder traversa
 * @tree: poibter to the root of the tree
 * @func: function to process the data of each node
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tmp;
	queue_t *head = NULL;

	if (tree == NULL || func == NULL)
		return;

	enque(&head, tree);
	while (head != NULL)
	{
		tmp = deque(&head);
		func(tmp->n);
		enque(&head, tmp->left);
		enque(&head, tmp->right);
	}
}

/**
 * enque - ...
 * @h: ...
 * @n: ...
 *
 */
void enque(queue_t **h, const binary_tree_t *n)
{
	queue_t *tmp, *node;

	if (h == NULL || n == NULL)
		return;

	node = malloc(sizeof(queue_t));
	if (node == NULL)
		return;

	node->n = (binary_tree_t *)n;
	node->next = NULL;
	tmp = *h;
	if (tmp == NULL)
		*h = node;

	else
	{
		while (1)
		{
			if (tmp->next == NULL)
			{
				tmp->next = node;
				return;
			}

			tmp = tmp->next;
		}
	}
}

/**
 * deque - ...
 * @h: ...
 *
 * Return: ...
 */
binary_tree_t *deque(queue_t **h)
{
	binary_tree_t *n;

	if (h == NULL || *h == NULL)
		return (NULL);

	n = (*h)->n;
	*h = (*h)->next;

	return (n);
}
