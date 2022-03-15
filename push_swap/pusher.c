/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:56:26 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/14 15:02:42 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_node **stack_b)
{
	int		max_index;
	t_node	*tmp;

	max_index = 0;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

void	smart_rotate(t_node **stack_a, t_node **stack_b, int len, int flag)
{
	while (len > 0)
	{
		if (flag == 1)
			ra(stack_a);
		else
			rb(stack_b);
		len--;
	}
	if (flag == 1)
		pb(stack_a, stack_b);
	else
		pa(stack_a, stack_b);
}

void	smart_reverse(t_node **stack_a, t_node **stack_b, int len, int flag)
{
	while (len > 0)
	{
		if (flag == 1)
			rra(stack_a);
		else
			rrb(stack_b);
		len--;
	}
	if (flag == 1)
		pb(stack_a, stack_b);
	else
		pa(stack_a, stack_b);
}

void	smart_stack_push(t_node **stack_a, t_node **stack_b, int index, \
int flag)
{
	int		len1;
	int		len2;
	t_node	*temp;

	len1 = 0;
	len2 = 0;
	if (flag == 1)
		temp = *stack_a;
	else
		temp = *stack_b;
	while ((temp)->index != index && temp->next)
	{
		temp = temp->next;
		len1++;
	}
	while (temp && temp->next)
	{
		temp = temp->next;
		len2++;
	}
	if (len1 < ++len2)
		smart_rotate(stack_a, stack_b, len1, flag);
	else
		smart_reverse(stack_a, stack_b, len2, flag);
}

void	pusher(t_node **stack_a, t_node **stack_b)
{
	int		maximum_index;
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	while (i - 1 > 0)
	{
		maximum_index = max_index(stack_b);
		smart_stack_push(stack_a, stack_b, maximum_index, 0);
		i--;
	}
	pa(stack_a, stack_b);
}
