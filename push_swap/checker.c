/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:42:28 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 14:57:07 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	determinant(char *line, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(line, "sa") == 0)
		return (sa(stack_a));
	else if (ft_strncmp(line, "sb") == 0)
		return (sb(stack_b));
	else if (ft_strncmp(line, "ss") == 0)
		return (ss(stack_a, stack_b));
	else if (ft_strncmp(line, "ra") == 0)
		return (ra(stack_a));
	else if (ft_strncmp(line, "rb") == 0)
		return (rb(stack_b));
	else if (ft_strncmp(line, "rr") == 0)
		return (rr(stack_a, stack_b));
	else if (ft_strncmp(line, "pa") == 0)
		return (pa(stack_a, stack_b));
	else if (ft_strncmp(line, "pb") == 0)
		return (pb(stack_a, stack_b));
	else if (ft_strncmp(line, "rra") == 0)
		return (rra(stack_a));
	else if (ft_strncmp(line, "rrb") == 0)
		return (rrb(stack_b));
	else if (ft_strncmp(line, "rrr") == 0)
		return (rrr(stack_a, stack_b));
	else
		return (1);
}

void	swaps_reader(t_node **stack_a, t_node **stack_b)
{
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (determinant(line, stack_a, stack_b) == 1)
			ft_error();
	}
	if (is_sorted(*stack_a) && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = 0;
	if (ac < 2)
	{
		write(1, "\n", 1);
		exit(0);
	}
	if (ac == 2)
		stack_a = quote_parser(av);
	else
		stack_a = initiator_parser(ac, av);
	check_duplicates_n_indexes(stack_a);
	swaps_reader(&stack_a, &stack_b);
	exit(0);
}
