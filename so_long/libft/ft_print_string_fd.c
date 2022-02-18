/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:25:57 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/10 16:43:33 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_fd(int fd, va_list tab)
{
	int		i;
	char	simbol;

	simbol = (char) va_arg(tab, int);
	i = write(fd, &simbol, 1);
	return (i);
}

int	print_string_fd(int fd, va_list tab)
{
	int		i;
	char	*str;

	str = (char *) va_arg(tab, char *);
	if (!str)
	{
		ft_putstr_fd ("(null)", fd);
		return (6);
	}
	i = ft_strlen(str);
	write (fd, str, i);
	return (i);
}

int	print_percent_fd(int fd, char tab)
{
	ft_putchar_fd(tab, fd);
	return (1);
}
