/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swaps_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:04:59 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 20:32:53 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sb(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*b || (*b)->next != NULL)
	{
		tmp = *b;
		tmp2 = (*b)->next;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		*b = tmp2;
	}
	return (0);
}

int	pb(t_node **a, t_node **b)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	if (*a)
	{
		tmp_b = *b;
		tmp_a = (*a)->next;
		*b = *a;
		(*b)->next = tmp_b;
		*a = tmp_a;
	}
	return (0);
}

int	rb(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*b)
	{
		tmp = *b;
		tmp2 = (*b)->next;
		*b = tmp2;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	return (0);
}

int	rrb(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*b && (*b)->next)
	{
		tmp = *b;
		while ((*b)->next->next != NULL)
			*b = (*b)->next;
		tmp2 = *b;
		*b = (*b)->next;
		(*b)->next = tmp;
		tmp2->next = NULL;
	}
	return (0);
}
