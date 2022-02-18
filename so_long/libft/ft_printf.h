/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:34:35 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/10 16:43:29 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "MyLibft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *printf, ...);
int	ft_printf_fd(int fd, const char *printf, ...);

int	print_char(va_list tab);
int	print_string(va_list tab);
int	print_pointer(va_list tab);
int	print_integer(va_list tab);
int	print_unsigned_integer(va_list tab);
int	print_hex(va_list tab);
int	print_upper_hex(va_list tab);
int	print_percent(char tab);

int	print_char_fd(int fd, va_list tab);
int	print_string_fd(int fd, va_list tab);
int	print_pointer_fd(int fd, va_list tab);
int	print_integer_fd(int fd, va_list tab);
int	print_unsigned_integer_fd(int fd, va_list tab);
int	print_hex_fd(int fd, va_list tab);
int	print_upper_hex_fd(int fd, va_list tab);
int	print_percent_fd(int fd, char tab);

#endif