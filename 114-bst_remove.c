#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node
{
	int value;
	struct bst_node *left;
	struct bst_node *right;
} bst_t;

bst_t *find_min(bst_t *node);
bst_t *bst_remove_node(bst_t *root, int value);

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
	{
	return (NULL);  // Value not found or empty tree
	}

	return bst_remove_node(root, value);
}

bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
	{
	node = node->left;
	}
	return (node);
}

bst_t *bst_remove_node(bst_t *root, int value)
{
	if (root == NULL)
	{
	return (NULL);  // Value not found
	}

	if (value < root->value)
	{
	root->left = bst_remove_node(root->left, value);
	}
	else if (value > root->value)
	{
	root->right = bst_remove_node(root->right, value);
	}
	else
	{
	// Node with only one child or no child
	if (root->left == NULL)
	{
	bst_t *temp = root->right;
		free(root);
		return (temp);
	}
	else if (root->right == NULL)
	{
		bst_t *temp = root->left;
		free(root);
		return (temp;)
	}

	// Node with two children: Get the in-order successor (smallest
	// in the right subtree)
	bst_t *temp = find_min(root->right);

	// Copy the in-order successor's value to this node
	root->value = temp->value;

	// Delete the in-order successor
	root->right = bst_remove_node(root->right, temp->value);
	}

	return (root);
}
