/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:30:56 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 13:52:23 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				index;
	int				value;
	int				len_a;
	int				len_b;

	struct s_node	*next;
}	t_node;

void	ft_error(void);
t_node	*get_last_node(t_node *stack_a);
void	check_duplicates_n_indexes(t_node *stack);
int		is_sorted(t_node *node);

size_t	ft_strlen(char *str);
t_node	*initiator_parser(int ac, char **av);
t_node	*quote_parser(char **av);

int		ft_atoi(char *str);

void	sorter(t_node **stack_a, t_node **stack_b);
void	sorter_of_3(t_node **stack_a);
void	sorter_of_4(t_node **stack_a, t_node **stack_b);
void	sorter_of_5(t_node **stack_a, t_node **stack_b);
void	large_sorter(t_node **stack_a, t_node **stack_b, int count);

int		max_index(t_node **stack_b);
void	smart_rotate(t_node **stack_a, t_node **stack_b, int len, int flag);
void	smart_reverse(t_node **stack_a, t_node **stack_b, int len, int flag);
void	smart_stack_push(t_node **stack_a, t_node **stack_b, int index, \
int flag);
void	pusher(t_node **stack_a, t_node **stack_b);

char	**ft_split(char const *s, char c);

void	sa(t_node **a);
void	pa(t_node **a, t_node **b);
void	ra(t_node **a);
void	rra(t_node **a);

void	sb(t_node **b);
void	pb(t_node **a, t_node **b);
void	rb(t_node **b);
void	rrb(t_node **b);

void	ss(t_node **a, t_node **b);
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
