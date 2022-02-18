/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:40:07 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 18:22:54 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t count)
{
	size_t			i;
	unsigned char	*copy_to;
	unsigned char	*copy_from;

	i = 0;
	copy_to = (unsigned char *) to;
	copy_from = (unsigned char *) from;
	if (copy_from == NULL && copy_to == NULL)
		return (NULL);
	if (copy_to > copy_from)
	{
		while (++i <= count)
			copy_to[count - i] = copy_from[count - i];
	}
	else
	{
		while (count > 0)
		{
			copy_to[i] = copy_from[i];
			i++;
			count--;
		}
	}
	return (to);
}
