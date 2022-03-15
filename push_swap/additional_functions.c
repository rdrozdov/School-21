/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:27:15 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 16:50:44 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	isspacer(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '	' || str[i] == '\t' || \
			str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || \
			str[i] == '\r')
			{
				i++;
			}
			else
				return (i);
		}
	}
	else
		ft_error();
	return (i);
}

static int	min_max_checker(int long long result)
{
	if (result < -2147483648 || result > 2147483647)
		ft_error();
	return ((int) result);
}

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	i = isspacer(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (int)(str[i++] - '0');
		else
			ft_error();
	}
	result *= sign;
	return (min_max_checker(result));
}
