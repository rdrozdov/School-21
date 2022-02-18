/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:43:04 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/10 16:43:32 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_part_fd(int fd, unsigned long long number, char *base)
{
	int		length_of_number;
	char	hex_parts[100];
	int		part_number;

	length_of_number = 0;
	part_number = 0;
	while (number >= 16)
	{
		hex_parts[part_number] = number % 16;
		number = number / 16;
		part_number++;
	}
	hex_parts[part_number] = number;
	while (part_number >= 0)
	{
		ft_putchar_fd(base[(int)hex_parts[part_number]], fd);
		part_number--;
		length_of_number++;
	}
	return (length_of_number);
}

int	print_pointer_fd(int fd, va_list tab)
{
	unsigned long long	number;

	number = (unsigned long long) va_arg(tab, long);
	if (!number)
	{
		ft_putstr_fd("0x0", fd);
		return (3);
	}
	else
	{
		ft_putstr_fd("0x", fd);
		return (print_hex_part_fd(fd, number, "0123456789abcdef") + 2);
	}
}
