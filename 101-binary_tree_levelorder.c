#include "binary_trees.h"

/**
 * height - To measure the height of a binary tree at a given node.
 * @tree: A pointer to the node.
 *
 * Return: 0 if tree is null
 *         Otherwise the height of the tree.
 */
int height(binary_tree_t *tree)
{
	int right, left;

	if (!tree)
		return (0);
	right = 1 + height(tree->right);
	left = 1 + height(tree->left);

	if (right > left)
		return (right);
	return (left);
}

/**
 * current_level - To print all the nodes at a given level.
 * @tree: A pointer to the node.
 * @func: A pointer to the function to print the node.
 * @level: The level to print the nodes.
 *
 * Return: always void.
 */
void current_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (!tree || !func)
		return;

	if (level == 1)
		func(tree->n);

	current_level(tree->left, func, level - 1);
	current_level(tree->right, func, level - 1);
}

/**
 * binary_tree_levelorder - To print all the levels of a given tree.
 * @tree: A pointer to the root.
 * @func: A pointer to the function to print a node.
 *
 * Return: always void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int level = 1, max;

	if (!tree || !func)
		return;

	max = height((binary_tree_t *)tree);

	while (level <= max)
		current_level(tree, func, level++);
}
