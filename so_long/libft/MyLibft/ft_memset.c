/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:03:02 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:34:37 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	char	*str;
	int		i;

	i = 0;
	str = buf;
	while (count > 0)
	{
		((unsigned char *)str)[i] = (unsigned char)ch;
		count--;
		i++;
	}
	return (str);
}
