/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:07:34 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 19:40:49 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_string(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	int_to_string(int n, int len, char *number, int minus)
{
	while (len > 0 && n != 0)
	{
		number[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	number[len] = n % 10 + '0';
	if (minus < 0)
		number[0] = '-';
	return (*number);
}

static char	*min_int_exception(int n)
{
	int		len;
	char	*number;
	int		minus;

	len = len_of_string(n);
	number = malloc (sizeof(char) * 12);
	number[len] = '\0';
	len--;
	number[len] = 8 + '0';
	n = n / 10 * (-1);
	len--;
	minus = -1;
	int_to_string(n, len, number, minus);
	return (number);
}

char	*ft_itoa(int n)
{
	int		len;
	int		minus;
	char	*number;

	if (n == -2147483648)
		return (min_int_exception(n));
	len = len_of_string(n);
	minus = 1;
	if (n < 0)
	{
		n *= (-1);
		minus *= (-1);
	}
	number = malloc (sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	number[len] = '\0';
	len--;
	if (n == 0)
	{
		number[0] = '0';
		return (number);
	}
	int_to_string(n, len, number, minus);
	return (number);
}
