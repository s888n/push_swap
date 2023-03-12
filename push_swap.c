/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:34:43 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/11 17:11:55 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **a, t_list **b)
{
	int	size;

	size = list_size(a);
	if (size < 1)
		return ;
	else if (size <= 5)
		simple(a, b);
	else if (size > 5 && size < 2000)
		bow_sort(a, b);
	else
		radix(a, b);
}

int	main(int ac, char *av[])
{
	t_list	**a;
	t_list	**b;

	if (ac < 2)
		return (0);
	a = (t_list **)malloc(sizeof(t_list));
	if (!a)
		error(NULL, NULL);
	*a = NULL;
	load_list(a, av);
	index_list(a);
	if (is_sorted(a))
	{
		free_list(a);
		return (0);
	}
	b = (t_list **)malloc(sizeof(t_list));
	if (!b)
		error(a, NULL);
	*b = NULL;
	sort_list(a, b);
	free_list(a);
	free_list(b);
	return (0);
}
