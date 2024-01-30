#include "binary_trees.h"

/**
 * binary_tree_height - To measure the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	right = 1 + binary_tree_height(tree->right);
	left = 1 + binary_tree_height(tree->left);

	if (right > left)
		return (right);
	return (left);
}

/**
 * binary_tree_balance - To measure the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t right_height = 0, left_height = 0;

	if (!tree)
		return (0);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	return (right_height - left_height);
}
