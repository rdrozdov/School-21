/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:06:23 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/14 15:06:55 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*a) || (*a)->next == NULL)
		return ;
	tmp = *a;
	tmp2 = (*a)->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	*a = tmp2;
	write(1, "sa\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	if (!(*b))
		return ;
	tmp_b = (*b)->next;
	tmp_a = *a;
	*a = *b;
	(*a)->next = tmp_a;
	*b = tmp_b;
	write(1, "pa\n", 3);
}

void	ra(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*a))
		return ;
	tmp = *a;
	tmp2 = (*a)->next;
	*a = tmp2;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*a))
		return ;
	tmp = *a;
	while ((*a)->next->next != NULL)
		*a = (*a)->next;
	tmp2 = *a;
	*a = (*a)->next;
	(*a)->next = tmp;
	tmp2->next = NULL;
	write(1, "rra\n", 4);
}
