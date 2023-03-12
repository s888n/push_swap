/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:17:37 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/11 17:53:44 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	run_ops(t_list **a, t_list **b, char *op)
{
	if (!ft_strcmp(op, "ra\n"))
		reverse_rotate(a, NULL);
	else if (!ft_strcmp(op, "rb\n"))
		reverse_rotate(b, NULL);
	else if (!ft_strcmp(op, "rr\n"))
		rrr(a, b, NULL);
	else if (!ft_strcmp(op, "sa\n"))
		swap(a, NULL);
	else if (!ft_strcmp(op, "sb\n"))
		swap(b, NULL);
	else if (!ft_strcmp(op, "ss\n"))
		ss(a, b, NULL);
	else if (!ft_strcmp(op, "pa\n"))
		push_pop(b, a, NULL);
	else if (!ft_strcmp(op, "pb\n"))
		push_pop(a, b, NULL);
	else if (!ft_strcmp(op, "rra\n"))
		rotate(a, NULL);
	else if (!ft_strcmp(op, "rrb\n"))
		rotate(b, NULL);
	else if (!ft_strcmp(op, "rrr\n"))
		rr(a, b, NULL);
	else
		return (0);
	return (1);
}

void	get_ops(t_list **a, t_list **b)
{
	char	*op;

	if (list_size(a) < 2)
		return ;
	op = NULL;
	while (get_next_line(0, &op))
	{
		if (!run_ops(a, b, op))
		{	
			free(op);
			error(a, b);
		}
		free (op);
	}
	if (is_sorted(a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char *av[])
{
	t_list	**a;
	t_list	**b;

	if (ac < 2)
		return (0);
	a = (t_list **)malloc(sizeof(t_list *));
	if (!a)
		error(a, NULL);
	*a = NULL;
	load_list(a, av);
	index_list(a);
	if (is_sorted(a))
	{
		free_list(a);
		return (0);
	}
	b = (t_list **)malloc(sizeof(t_list *));
	if (!b)
		error(a, b);
	*b = NULL;
	get_ops(a, b);
	free_list(a);
	free_list(b);
	return (0);
}
