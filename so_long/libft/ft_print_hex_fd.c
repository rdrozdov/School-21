/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:43:42 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/10 16:43:32 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_number_fd(int fd, unsigned int nubmer, const char *base)
{
	unsigned int	res_number;
	int				length_of_number;
	char			hex_parts[100];
	int				part_number;

	length_of_number = 0;
	part_number = 0;
	res_number = nubmer;
	if (nubmer < 0)
		res_number = 4294967295 + nubmer;
	while (res_number >= 16)
	{
		hex_parts[part_number] = res_number % 16;
		res_number = res_number / 16;
		part_number++;
	}
	hex_parts[part_number] = res_number;
	while (part_number >= 0)
	{
		ft_putchar_fd(base[(int)hex_parts[part_number]], fd);
		part_number--;
		length_of_number++;
	}
	return (length_of_number);
}

int	print_hex_fd(int fd, va_list tab)
{
	int		number;
	char	*base;

	base = "0123456789abcdef";
	number = va_arg(tab, int);
	return (print_hex_number_fd(fd, number, base));
}

int	print_upper_hex_fd(int fd, va_list tab)
{
	int		number;
	char	*base;

	base = "0123456789ABCDEF";
	number = va_arg(tab, int);
	return (print_hex_number_fd(fd, number, base));
}
