/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:07:49 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 19:40:56 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int ch, size_t count)
{
	size_t			i;
	unsigned char	*str;

	if (count != 0)
	{
		i = 0;
		str = (unsigned char *)buffer;
		while (i < count)
		{
			if (*(str + i) == (unsigned char)ch)
			{
				return (str + i);
			}
			i++;
		}
	}
	return (NULL);
}
