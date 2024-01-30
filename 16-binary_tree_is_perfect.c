#include "binary_trees.h"

/**
 * binary_tree_depth - To measure the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, your function must return 0, else return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || !tree->parent)
		return (count);

	count = 1 + binary_tree_depth(tree->parent);

	return (count);
}

/**
 * binary_tree_nodes - Count the nodes with at least 1 child in a binary tree.
 * @tree: Pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	count += 1;
	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);

}

/**
 * binary_tree_is_full - To check if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not full - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		l = binary_tree_is_full(tree->left);
		r = binary_tree_is_full(tree->right);
		return (l * r);
	}
	return (0);

}

/**
 * binary_tree_is_perfect - To check if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (binary_tree_is_full(tree) == 0)
		return (0);

	if (binary_tree_depth(tree->left) == binary_tree_depth(tree->right))
	{
		l = binary_tree_nodes(tree->left);
		r = binary_tree_nodes(tree->right);
		if (l == r)
			return (1);
	}

	return (0);

}
