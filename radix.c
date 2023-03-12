/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:23:42 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/08 17:26:55 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bit(t_list **list)
{
	int	max;
	int	maxbit;

	maxbit = 0;
	max = find_max(list);
	while (max >> maxbit)
		maxbit++;
	return (maxbit);
}

void	radix(t_list **a, t_list **b)
{
	int	maxbit;
	int	size;
	int	i;
	int	j;

	i = 0;
	maxbit = get_max_bit(a);
	size = list_size(a);
	while (i < maxbit)
	{
		j = 0;
		while (j < size)
		{
			if ((*a)->index >> i & 1)
				rotate(a, "ra\n");
			else
				push_pop(a, b, "pb\n");
			j++;
		}
		while (*b)
			push_pop(b, a, "pa\n");
		i++;
	}	
}
