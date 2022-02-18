/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:37:41 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/10 16:43:31 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer_fd(int fd, va_list tab)
{
	char	*str;
	int		number;
	int		i;

	i = 0;
	number = (int) va_arg(tab, int);
	str = ft_itoa(number);
	i += ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (i);
}

static long	len_of_string(long n)
{
	long	len;

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

static char	int_to_string(long n, int len, char *number, int minus)
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

static char	*dec_ft_itoa(long n)
{
	long	len;
	int		minus;
	char	*number;

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

int	print_unsigned_integer_fd(int fd, va_list tab)
{
	char			*str;
	unsigned int	number;
	int				i;

	i = 0;
	number = (unsigned int) va_arg(tab, unsigned int);
	str = dec_ft_itoa(number);
	i += ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (i);
}
