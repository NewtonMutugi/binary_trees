#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	/* allocate memory for new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* assign data to this node */
	new_node->n = value;

	/* initialize left and right children as NULL */
	new_node->left = NULL;
	new_node->right = NULL;

	/* check if the  parent node is NULL */
	if (parent == NULL)
	{
		new_node->parent = NULL;
		return (new_node);
	}

	/* assign parent to this node */
	new_node->parent = parent;

	return (new_node);
}
