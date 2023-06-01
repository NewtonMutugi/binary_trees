#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, return 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t level, i;

	if (tree == NULL)
		return (0);

	/* nodes = binary_tree_nodes(tree);*/
	level = binary_tree_height(tree) + 1;

	for (i = 1; i <= level; i++)
	{
		if (i == level)
		{
			if (binary_tree_is_perfect(tree) == 1)
				return (1);
			return (0);
		}
		if (binary_tree_is_perfect(tree) == 1)
			return (0);
		tree = tree->left;
	}
	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t nodes, height;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_nodes(tree);
	height = binary_tree_height(tree);

	if (nodes == (size_t)(2 << height) - 1)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves in
 *
 * Return: If tree is NULL, the function must return 0
 * A NULL pointer is not a node
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		nodes++;

	return (nodes);
}
