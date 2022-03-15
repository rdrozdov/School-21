/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_duo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:54:30 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/14 15:10:13 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*tmp4;

	if (!(*a) || (*a)->next == NULL)
		return ;
	tmp = *a;
	tmp2 = (*a)->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	*a = tmp2;
	if (!(*b) || (*b)->next == NULL)
		return ;
	tmp3 = *b;
	tmp4 = (*b)->next;
	tmp3->next = tmp4->next;
	tmp4->next = tmp3;
	*b = tmp4;
	write (1, "ss\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*tmp4;

	if (!(*a))
		return ;
	tmp = *a;
	tmp2 = (*a)->next;
	*a = tmp2;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (!(*b))
		return ;
	tmp3 = *b;
	tmp4 = (*b)->next;
	*b = tmp4;
	while (tmp4->next != NULL)
		tmp4 = tmp4->next;
	tmp4->next = tmp3;
	tmp3->next = NULL;
	write (1, "rr\n", 3);
}

void	rrr(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*tmp4;

	if (!(*a))
		return ;
	tmp = *a;
	while ((*a)->next->next != NULL)
		*a = (*a)->next;
	tmp2 = *a;
	*a = (*a)->next;
	(*a)->next = tmp;
	tmp2->next = NULL;
	if (!(*b))
		return ;
	tmp3 = *b;
	while ((*b)->next->next != NULL)
		*b = (*b)->next;
	tmp4 = *b;
	*b = (*b)->next;
	(*b)->next = tmp3;
	tmp4->next = NULL;
	write (1, "rrr\n", 4);
}
