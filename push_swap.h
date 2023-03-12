/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:12:07 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/11 17:23:56 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

t_list		*new_node(int value);
void		lst_add_front(t_list **head, t_list *node);
void		lst_add_back(t_list **head, t_list *node);
t_list		*last_node(t_list **head);
int			list_size(t_list **head);
t_list		*get_min_node(t_list **stack);
void		index_list(t_list **stack);
void		free_list(t_list **head);
int			is_sorted(t_list **stack);
void		push_min_to_b(t_list **a, t_list **b);
void		push_pop(t_list **from, t_list **to, char *op);
void		push(t_list **stack, t_list *n);
t_list		*pop(t_list **stack);
void		swap(t_list **stack, char *op);
void		rotate(t_list **stack, char *op);
void		reverse_rotate(t_list **stack, char *op);
void		ss(t_list **a, t_list **b, char *op);
void		rr(t_list **a, t_list **b, char *op);
void		rrr(t_list **a, t_list **b, char *op);
void		load_list(t_list **stack, char *av[]);
void		sort_list(t_list **a, t_list **b);
int			main(int ac, char *av[]);
void		simple(t_list **a, t_list **b);
void		sort_two(t_list **a);
void		sort_three(t_list **a);
void		sort_four(t_list **a, t_list **b);
void		sort_five(t_list **a, t_list **b);
int			is_digit(char c);
void		ft_putstr(char *str);
int			has_duplicates(t_list **stack);
int			ft_atoi(char *str, t_list **stack);
void		error(t_list **a, t_list **b);
char		**failed_allocation(int i, char **ptr);
size_t		word_count(char *str, char c);
char		*word(char *str, char c);
char		**split(char *str, char c);
int			is_space(char *s);
int			only_space(char	*s);
int			find_max(t_list **a);
t_list		*min(t_list **a);
int			distance_to_index(t_list **a, int n);
void		bow_sort(t_list **a, t_list **b);
void		pushback(t_list **a, t_list **b);
void		pushback2(t_list **a, t_list **b, int position);
int			get_max_bit(t_list **list);
void		radix(t_list **a, t_list **b);
#endif
