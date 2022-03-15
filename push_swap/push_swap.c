/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:31:02 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 13:58:32 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_node	*get_last_node(t_node *stack_a)
{
	t_node	*last_node;

	last_node = stack_a;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

void	check_duplicates_n_indexes(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack;
	tmp2 = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				ft_error();
			if (tmp->value > tmp2->value)
				tmp->index += 1;
			else
				tmp2->index += 1;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	is_sorted(t_node *node)
{
	while (node->next)
	{
		if (node->index < node->next->index)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
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
	if (is_sorted(stack_a) == 0)
		sorter(&stack_a, &stack_b);
	exit(0);
}
