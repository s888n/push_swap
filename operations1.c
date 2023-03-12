/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:06:00 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/08 17:45:54 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop(t_list **stack)
{
	t_list	*node;

	node = *stack;
	if (*stack == NULL)
		return (NULL);
	*stack = (*stack)->next;
	return (node);
}

void	push(t_list **stack, t_list *n)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->value = n->value;
	node->index = n->index;
	node->next = *stack;
	*stack = node;
	free (n);
}

void	push_pop(t_list **from, t_list **to, char *op)
{
	t_list	*node;

	node = pop(from);
	if (node == NULL)
		return ;
	push(to, node);
	if (op)
		ft_putstr(op);
}

void	swap(t_list **stack, char *op)
{
	t_list	*node1;
	t_list	*node2;

	if (list_size(stack) < 2)
		return ;
	node1 = *stack;
	node2 = node1->next;
	if (node2 == NULL || node1 == NULL)
		return ;
	node1->next = node2->next;
	node2->next = node1;
	*stack = node2;
	if (op)
		ft_putstr(op);
}

void	push_min_to_b(t_list **a, t_list **b)
{
	t_list	*m;
	int		distance;

	m = min(a);
	distance = distance_to_index(a, m->index);
	while (*a != m)
	{
		if (distance > list_size(a) / 2)
			rotate(a, "rra\n");
		else
			reverse_rotate(a, "ra\n");
	}
	if (is_sorted(a))
		return ;
	push_pop(a, b, "pb\n");
}
