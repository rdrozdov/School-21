/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:17:50 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/14 15:03:38 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->len_a == 3)
		sorter_of_3(stack_a);
	else if ((*stack_a)->len_a == 4)
		sorter_of_4(stack_a, stack_b);
	else if ((*stack_a)->len_a == 5)
		sorter_of_5(stack_a, stack_b);
	else if ((*stack_a)->len_a > 100)
		large_sorter(stack_a, stack_b, 30);
	else
		large_sorter(stack_a, stack_b, 15);
}

void	sorter_of_3(t_node **stack_a)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	if (((*stack_a)->index > (*stack_a)->next->index && \
	((*stack_a)->index > (*stack_a)->next->next->index)))
	{
		ra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
	else if (((*stack_a)->index < (*stack_a)->next->index) && \
	((*stack_a)->index > (*stack_a)->next->next->index))
		rra(stack_a);
	else if (((*stack_a)->index < (*stack_a)->next->index) && \
	((*stack_a)->next->index > (*stack_a)->next->next->index))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (((*stack_a)->index > (*stack_a)->next->index) && \
	((*stack_a)->index < (*stack_a)->next->next->index))
		sa(stack_a);
	else
		ra(stack_a);
	return ;
}

void	sorter_of_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	pb(stack_a, stack_b);
	sorter_of_3(stack_a);
	pa(stack_a, stack_b);
	if (is_sorted(*stack_a) == 1)
		exit(0);
	temp = get_last_node(*stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		if ((*stack_a)->index < (*stack_a)->next->next->index)
			sa(stack_a);
		else if ((*stack_a)->index > temp->index)
			ra(stack_a);
		else
		{
			rra(stack_a);
			sa(stack_a);
			ra(stack_a);
			ra(stack_a);
		}
	}
}

void	sorter_of_5(t_node **stack_a, t_node **stack_b)
{
	smart_stack_push(stack_a, stack_b, 0, 1);
	smart_stack_push(stack_a, stack_b, 1, 1);
	sorter_of_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	large_sorter(t_node **stack_a, t_node **stack_b, int count)
{
	int	i;

	i = 0;
	while (*stack_a != NULL)
	{
		if (i > 1 && (*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + count)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index >= i)
			ra(stack_a);
	}
	pusher(stack_a, stack_b);
}
