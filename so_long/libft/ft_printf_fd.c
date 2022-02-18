/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:33:52 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/10 16:43:34 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion_printf_fd(int fd, va_list tab, char print_type)
{
	if (print_type == 'c')
		return (print_char_fd(fd, tab));
	if (print_type == 's')
		return (print_string_fd(fd, tab));
	if (print_type == 'i')
		return (print_integer_fd(fd, tab));
	if (print_type == 'd')
		return (print_integer_fd(fd, tab));
	if (print_type == 'u')
		return (print_unsigned_integer_fd(fd, tab));
	if (print_type == 'p')
		return (print_pointer_fd(fd, tab));
	if (print_type == 'x')
		return (print_hex_fd(fd, tab));
	if (print_type == 'X')
		return (print_upper_hex_fd(fd, tab));
	if (print_type == '%')
		return (print_percent_fd(fd, '%'));
	else
		return (0);
}

int	ft_printf_fd(int fd, const char *format, ...)
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
			print_result += conversion_printf_fd(fd, tab, format[counter + 1]);
			counter = counter + 2;
		}
		else
		{
			write(fd, &format[counter], 1);
			print_result++;
			counter++;
		}
	}
	va_end(tab);
	return (print_result);
}
