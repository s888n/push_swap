/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:56:08 by srachdi           #+#    #+#             */
/*   Updated: 2023/02/27 23:59:52 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	lst_add_front(t_list **head, t_list *node)
{
	node->next = *head;
	*head = node;
}

void	lst_add_back(t_list **head, t_list *node)
{
	t_list	*last;

	if (*head)
	{
		last = last_node(head);
		last->next = node;
		node->next = NULL;
	}
	else
	{
		*head = node;
		node->next = NULL;
	}
}

t_list	*last_node(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	list_size(t_list **head)
{
	size_t	count;
	t_list	*tmp;

	tmp = *head;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
