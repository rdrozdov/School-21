/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:05:24 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 15:14:35 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			str[i] == '\r' \
			|| str[i] == '"')
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
		else if (str[i] == '"' || str[i] == ' ')
			i++;
		else
			ft_error();
	}
	result *= sign;
	return (min_max_checker(result));
}
