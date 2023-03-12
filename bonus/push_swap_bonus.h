/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:22:24 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/10 16:19:32 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strcmp(char *s1, char *s2);
int		ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *storage, char *readstr);
char	*get_next_line(int fd, char **line);
char	*readAndStore(int fd, char *storage);
char	*resetStorage(char *storage);
char	*extractLine(char *storage);
void	get_ops(t_list **a, t_list **b);
int		run_ops(t_list **a, t_list **b, char *op);
#endif
