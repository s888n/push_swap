/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:39:13 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/08 17:13:31 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **a)
{
	t_list	*tmp;
	int		max;

	tmp = *a;
	max = (*a)->index;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	distance_to_index(t_list **a, int n)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp && tmp->index != n)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	bow_sort(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = 0;
	j = 15;
	if (list_size(a) >= 500)
		j = 40;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			push_pop(a, b, "pb\n");
			i++;
		}
		else if ((*a)->index <= i + j)
		{
			push_pop(a, b, "pb\n");
			reverse_rotate(b, "rb\n");
			i++;
		}
		else
			reverse_rotate(a, "ra\n");
	}
	pushback(a, b);
}

void	pushback(t_list **a, t_list **b)
{
	int	distance;
	int	position;

	while (*b)
	{
		position = distance_to_index(b, find_max(b));
		if (position < (int)list_size(b) / 2)
		{
			distance = position;
			while (distance)
			{
				reverse_rotate(b, "rb\n");
				distance--;
			}
			push_pop(b, a, "pa\n");
		}
		else
			pushback2(a, b, position);
	}
}

void	pushback2(t_list **a, t_list **b, int position)
{
	int	moves;

	if (position > (int)list_size(b) / 2)
	{
		moves = list_size(b) - position;
		while (moves)
		{
			rotate(b, "rrb\n");
			moves--;
		}
		push_pop(b, a, "pa\n");
	}
	else if (position == list_size(b) / 2)
	{
		moves = position;
		while (moves)
		{
			reverse_rotate(b, "rb\n");
			moves--;
		}
		push_pop(b, a, "pa\n");
	}
}
