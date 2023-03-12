/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:46:02 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/11 17:25:42 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &(*str++), 1);
}

int	has_duplicates(t_list **stack)
{
	t_list	*curr;
	t_list	*tmp;

	curr = *stack;
	tmp = NULL;
	while (curr != NULL)
	{
		tmp = curr->next;
		while (tmp != NULL)
		{
			if (curr->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	ft_atoi(char *str, t_list **stack)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= sign;
	if (num < -2147483648 || 2147483647 < num)
		error(stack, NULL);
	return ((int)num);
}

int	only_space(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
