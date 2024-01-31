#include "binary_trees.h"

/**
 * array_to_bst - To insert a new node in a Binary Search Tree
 * @array: an arrya to use
 * @size: an array size
 *
 * Return: If no common ancestor was found return NULL
 */
#include <stddef.h>

typedef struct binary_tree_s
{
	int value;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
}
binary_tree_t;

int is_bst_util(const binary_tree_t *node, int *prev_value);

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_value = INT_MIN;  // Start with the smallest possible value
	return is_bst_util(tree, &prev_value);
}

int is_bst_util(const binary_tree_t *node, int *prev_value):
	if (node == NULL)
{
		return 1;  // An empty tree is a BST
	}

	// Check the left subtree
	if (!is_bst_util(node->left, prev_value))
	{
	return 0;
	}

	// Check the current node's value
	if (node->value <= *prev_value)
	{
	return 0;  // Violation of the BST property
	}

	// Update the previous value
	*prev_value = node->value;

	// Check the right subtree
	return is_bst_util(node->right, prev_value);
}
