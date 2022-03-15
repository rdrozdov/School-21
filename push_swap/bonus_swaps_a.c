/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swaps_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:02:19 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 20:33:38 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sa(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*a || (*a)->next != NULL)
	{
		tmp = *a;
		tmp2 = (*a)->next;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		*a = tmp2;
	}
	return (0);
}

int	pa(t_node **a, t_node **b)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	if (*b)
	{
		tmp_b = (*b)->next;
		tmp_a = *a;
		*a = *b;
		(*a)->next = tmp_a;
		*b = tmp_b;
	}
	return (0);
}

int	ra(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*a)
	{
		tmp = *a;
		tmp2 = (*a)->next;
		*a = tmp2;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
	return (0);
}

int	rra(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*a && (*a)->next)
	{
		tmp = *a;
		while ((*a)->next->next != NULL)
			*a = (*a)->next;
		tmp2 = *a;
		*a = (*a)->next;
		(*a)->next = tmp;
		tmp2->next = NULL;
	}
	return (0);
}
