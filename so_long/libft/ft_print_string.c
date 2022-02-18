/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:25:57 by gcolene           #+#    #+#             */
/*   Updated: 2021/11/25 16:22:23 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list tab)
{
	int		i;
	char	simbol;

	simbol = (char) va_arg(tab, int);
	i = write(1, &simbol, 1);
	return (i);
}

int	print_string(va_list tab)
{
	int		i;
	char	*str;

	str = (char *) va_arg(tab, char *);
	if (!str)
	{
		ft_putstr_fd ("(null)", 1);
		return (6);
	}
	i = ft_strlen(str);
	write (1, str, i);
	return (i);
}

int	print_percent(char tab)
{
	ft_putchar_fd(tab, 1);
	return (1);
}
