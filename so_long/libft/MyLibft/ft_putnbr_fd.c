/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:39:58 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:34:24 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	char			a;

	i = 0;
	if (n < 0)
	{
		write (fd, "-", 1);
		i = n * (-1);
	}
	else
	{
		i = n;
	}
	if (i < 10)
	{
		a = (i % 10) + '0';
		write (fd, &a, 1);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}
