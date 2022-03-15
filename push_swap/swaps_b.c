/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:54:17 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/14 15:10:27 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*b) || (*b)->next == NULL)
		return ;
	tmp = *b;
	tmp2 = (*b)->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	*b = tmp2;
	write (1, "sb\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	if (!(*a))
		return ;
	tmp_b = *b;
	tmp_a = (*a)->next;
	*b = *a;
	(*b)->next = tmp_b;
	*a = tmp_a;
	write (1, "pb\n", 3);
}

void	rb(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*b))
		return ;
	tmp = *b;
	tmp2 = (*b)->next;
	*b = tmp2;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp->next = NULL;
	write (1, "rb\n", 3);
}

void	rrb(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*b))
		return ;
	tmp = *b;
	while ((*b)->next->next != NULL)
		*b = (*b)->next;
	tmp2 = *b;
	*b = (*b)->next;
	(*b)->next = tmp;
	tmp2->next = NULL;
	write (1, "rrb\n", 4);
}
