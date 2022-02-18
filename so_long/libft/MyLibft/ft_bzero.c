/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:57:23 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/18 15:59:59 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *buf, size_t count)
{
	char	*str;

	str = buf;
	if (count != 0)
	{
		str = buf;
		while (count--)
		{
			*str++ = 0;
		}
	}
	return (buf);
}
