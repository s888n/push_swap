/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:00:12 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/08 17:52:36 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_min_node(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		hasmin;

	min = NULL;
	hasmin = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!hasmin || head->value < min->value))
			{
				min = head;
				hasmin = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_list(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_min_node(stack);
	if (head)
	{
		while (head)
		{
			head->index = index++;
			head = get_min_node(stack);
		}
	}
}

void	free_list(t_list **head)
{
	t_list	*tmp;

	tmp = NULL;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	free(head);
	head = NULL;
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

t_list	*min(t_list **a)
{
	t_list	*min;
	t_list	*current;

	min = *a;
	current = (*a)->next;
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	return (min);
}
