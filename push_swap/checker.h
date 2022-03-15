/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:43:14 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 15:03:03 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

void	check_duplicates_n_indexes(t_node *stack);
int		is_sorted(t_node *node);
int		ft_atoi(char *str);

t_node	*initiator_parser(int ac, char **av);
t_node	*quote_parser(char **av);

int		determinant(char *line, t_node **stack_a, t_node **stack_b);
void	swaps_reader(t_node **stack_a, t_node **stack_b);
void	ft_error(void);

char	*get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int ch);
char	*ft_substr(char *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

int		sa(t_node **a);
int		pa(t_node **a, t_node **b);
int		ra(t_node **a);
int		rra(t_node **a);

int		sb(t_node **b);
int		pb(t_node **a, t_node **b);
int		rb(t_node **b);
int		rrb(t_node **b);

int		ss(t_node **a, t_node **b);
int		rr(t_node **a, t_node **b);
int		rrr(t_node **a, t_node **b);
int		ft_strncmp(const char *str1, const char *str2);
size_t	ft_strlen_str(const char *str);

#endif
