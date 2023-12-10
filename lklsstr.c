#include "shell.h"

/**
 * add_nodes - add nodes to list
 * @head: input
 * @str: input
 * @num: input
 * Return: number
 */

list_t *add_nodes(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_T));
	if (!new_head)
		return (NULL);
	_mmset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdupp(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_nodeend -  add nodes in end of list
 * @head: input
 * @str: input
 * @num: input
 * Return: number
 */

list_t *add_nodeend(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_mmset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdupp(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * prt_ls_str - print str element
 * @j: input
 * Return: number
 */

size_t prt_ls_str(const list_t *j)
{
	size_t i = 0;

	while (j)
	{
		_puts(j->str ? j->str : "(nil)");
		_puts("\n");
		j = j->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_index - delete nodes
 * @head: input
 * @index: input
 * Return: 1,0
 */

int delete_node_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_ls - free all nodes
 * @head_point: input
 * Return: void
 */

void free_ls(list_t **head_point)
{
	list_t *node, *next_node, *head;

	if (!head_point || !*head_point)
		return;
	head = *head_point;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_point = NULL;
}
