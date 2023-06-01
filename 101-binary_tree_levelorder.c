#include "binary_trees.h"

/**
 * binary_tree_levelorder_func - goes through a binary tree using
 * level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * @level: is the level of the tree to traverse
 *
 * Return: If tree or func is NULL, do nothing
 */

void binary_tree_levelorder_func(const binary_tree_t *tree, void (*func)(int),
				 size_t level)
{
	if (tree == NULL || func == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		binary_tree_levelorder_func(tree->left, func, level - 1);
		binary_tree_levelorder_func(tree->right, func, level - 1);
	}
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
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Return: If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);

	for (i = 1; i <= height + 1; i++)
		binary_tree_levelorder_func(tree, func, i);
}
