#include "binary_trees.h"

/**
 * binary_tree_sibling - To find the sibling of a
 *                       node in a binary tree.
 * @node: Pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (!node->parent->left || !node->parent->right)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);

}
