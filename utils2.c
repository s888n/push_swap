/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:50:28 by srachdi           #+#    #+#             */
/*   Updated: 2023/02/27 23:52:20 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**failed_allocation(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

size_t	word_count(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			while (*str && *str != c)
				str++;
			count++;
		}
	}
	return (count);
}

char	*word(char *str, char c)
{
	size_t	i;
	char	*wd;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	wd = (char *)malloc(sizeof(char) * (i + 1));
	if (!wd)
		return (NULL);
	i = 0;
	while (*str && *str != c)
	{
		wd[i] = *str;
		i++;
		str++;
	}
	wd[i] = '\0';
	return (wd);
}

char	**split(char *str, char c)
{
	size_t	wc;
	char	**s;
	int		i;

	wc = word_count(str, c);
	if (!str)
		return (NULL);
	s = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	if (!s)
		return (NULL);
	while (i < (int)wc)
	{
		while (*str && *str == c)
			str++;
		s[i] = word(str, c);
		if (!s[i])
			failed_allocation(i, s);
		while (*str && *str != c)
			str++;
		i++;
	}
	s[i] = 0;
	return (s);
}
