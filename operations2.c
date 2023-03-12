/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:09:17 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/11 17:08:04 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char *op)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL || list_size(stack) < 2)
		return ;
	tmp = (*stack)->next;
	last_node(stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
	if (op)
		ft_putstr(op);
}

void	rotate(t_list **stack, char *op)
{
	t_list	*tmp;
	t_list	*head;

	tmp = *stack;
	head = *stack;
	if (tmp == NULL || tmp->next == NULL || list_size(stack) < 2)
		return ;
	*stack = last_node(stack);
	while (head->next->next)
		head = head->next;
	head->next = NULL;
	(*stack)->next = tmp;
	if (op)
		ft_putstr(op);
}

void	ss(t_list **a, t_list **b, char *op)
{
	swap(a, NULL);
	swap(b, NULL);
	if (op)
		ft_putstr(op);
}

void	rr(t_list **a, t_list **b, char *op)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (op)
		ft_putstr(op);
}

void	rrr(t_list **a, t_list **b, char *op)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	if (op)
		ft_putstr(op);
}
