#include "binary_trees.h"

void enque_all(queue_t **h, const binary_tree_t *n);
void _enque(queue_t **h, const binary_tree_t *n);
binary_tree_t *_deque(queue_t **h);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *head = NULL;
	binary_tree_t *tmp;

	if (tree == NULL)
		return (0);

	enque_all(&head, tree);
	while(head)
	{
		tmp = _deque(&head);
		if (tmp)
			printf("%d\n", tmp->n);
		printf("null\n");
	}

	while (head)
	{
		tmp = _deque(&head);
		if (tmp == NULL && head->next)
			return (0);
	}

	return (1);
}

/**
 * enque_all - ...
 * @h: ...
 * @n: ...
 *
 */
void enque_all(queue_t **h, const binary_tree_t *n)
{
	if (n == NULL)
		return;

	_enque(h, n);
	enque_all(h, n->left);
	enque_all(h, n->right);
}

/**
 * _enque - ...
 * @h: ...
 * @n: ...
 *
 */
void _enque(queue_t **h, const binary_tree_t *n)
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
 * _deque - ...
 * @h: ...
 *
 * Return: ...
 */
binary_tree_t *_deque(queue_t **h)
{
	binary_tree_t *n;

	if (h == NULL || *h == NULL)
		return (NULL);

	n = (*h)->n;
	*h = (*h)->next;

	return (n);
}
