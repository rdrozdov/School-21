/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:33:52 by gcolene           #+#    #+#             */
/*   Updated: 2021/11/25 16:20:11 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion_printf(va_list tab, char print_type)
{
	if (print_type == 'c')
		return (print_char(tab));
	if (print_type == 's')
		return (print_string(tab));
	if (print_type == 'i')
		return (print_integer(tab));
	if (print_type == 'd')
		return (print_integer(tab));
	if (print_type == 'u')
		return (print_unsigned_integer(tab));
	if (print_type == 'p')
		return (print_pointer(tab));
	if (print_type == 'x')
		return (print_hex(tab));
	if (print_type == 'X')
		return (print_upper_hex(tab));
	if (print_type == '%')
		return (print_percent('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	tab;
	int		counter;
	int		print_result;

	va_start(tab, format);
	counter = 0;
	print_result = 0;
	while (format[counter] != '\0')
	{
		if (format[counter] == '%')
		{
			print_result += conversion_printf(tab, format[counter + 1]);
			counter = counter + 2;
		}
		else
		{
			write(1, &format[counter], 1);
			print_result++;
			counter++;
		}
	}
	va_end(tab);
	return (print_result);
}
