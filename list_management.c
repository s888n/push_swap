/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:53:02 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/11 17:05:42 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check(char *s, t_list **stack)
{
	int	i;

	i = 0;
	if (!s[i])
		error (stack, NULL);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!is_digit(s[i]))
			error (stack, NULL);
		i++;
	}
}

static void	split_args(t_list **a, char *str)
{
	int		i;
	char	**args;

	i = 0;
	args = split(str, ' ');
	while (args[i])
	{
		check(args[i], a);
		lst_add_back(a, new_node(ft_atoi(args[i], a)));
		free(args[i]);
		i++;
	}
	free(args);
}

void	error(t_list **a, t_list **b)
{
	write(1, "Error\n", 6);
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	exit (1);
}

void	load_list(t_list **stack, char *av[])
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (only_space(av[i]))
			error(stack, NULL);
		if (is_space(av[i]))
			split_args(stack, av[i]);
		else
		{
			check(av[i], stack);
			lst_add_back(stack, new_node(ft_atoi(av[i], stack)));
		}
		i++;
	}
	if (has_duplicates(stack))
		error(stack, NULL);
}
