/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:43:22 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/10 16:18:47 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **A)
{
	if (!is_sorted(A))
		swap(A, "sa\n");
}

void	sort_three(t_list **a)
{
	int	max;

	max = find_max(a);
	if ((*a)->index == max)
		reverse_rotate(a, "ra\n");
	else if ((*a)->next->index == max)
		rotate(a, "rra\n");
	if ((*a)->index > (*a)->next->index)
		swap(a, "sa\n");
}

void	sort_four(t_list **a, t_list **b)
{
	push_min_to_b(a, b);
	if (is_sorted(a) && !*b)
		return ;
	sort_three(a);
	push_pop(b, a, "pa\n");
}

void	sort_five(t_list **a, t_list **b)

{
	push_min_to_b(a, b);
	if (is_sorted(a) && !*b)
		return ;
	sort_four(a, b);
	push_pop(b, a, "pa\n");
}

void	simple(t_list **a, t_list **b)
{
	if (is_sorted(a) && !*b)
		return ;
	if (list_size(a) == 2)
		sort_two(a);
	if (list_size(a) == 3)
		sort_three(a);
	if (list_size(a) == 4)
		sort_four(a, b);
	if (list_size(a) == 5)
		sort_five(a, b);
}
