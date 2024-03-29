#include "binary_trees.h"

/**
 * binary_tree_is_root - To check if a node is a root of a binary tree.
 * @node: Pointer to the node to check.
 *
 * Return: If the node is a root - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->parent)
		return (1);
	else
		return (0);
}
