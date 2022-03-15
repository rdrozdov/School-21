/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swaps_duo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:06:12 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 20:31:58 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ss(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*tmp4;

	if (!(*a) || (*a)->next == NULL)
		return (1);
	tmp = *a;
	tmp2 = (*a)->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	*a = tmp2;
	if (!(*b) || (*b)->next == NULL)
		return (1);
	tmp3 = *b;
	tmp4 = (*b)->next;
	tmp3->next = tmp4->next;
	tmp4->next = tmp3;
	*b = tmp4;
	return (0);
}

int	rr(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*tmp4;

	if (*a && *b)
	{
		tmp = *a;
		tmp2 = (*a)->next;
		*a = tmp2;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
		tmp3 = *b;
		tmp4 = (*b)->next;
		*b = tmp4;
		while (tmp4->next != NULL)
			tmp4 = tmp4->next;
		tmp4->next = tmp3;
		tmp3->next = NULL;
	}
	return (0);
}

int	rrr(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*tmp4;

	if (*a && *b && (*a)->next && (*b)->next)
	{
		tmp = *a;
		while ((*a)->next->next != NULL)
			*a = (*a)->next;
		tmp2 = *a;
		*a = (*a)->next;
		(*a)->next = tmp;
		tmp2->next = NULL;
		tmp3 = *b;
		while ((*b)->next->next != NULL)
			*b = (*b)->next;
		tmp4 = *b;
		*b = (*b)->next;
		(*b)->next = tmp3;
		tmp4->next = NULL;
	}
	return (0);
}

size_t	ft_strlen_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *str1, const char *str2)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen_str(str1);
	while (str1[i + 1] != '\0' && str2[i] != '\0' && str1[i] == str2[i] && \
	(i != len))
		i++;
	if (str1[i] == str2[i])
		return (0);
	if (str1[i] == '\n' && str2[i] == '\0')
		return (0);
	return (1);
}
