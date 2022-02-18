/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:32:05 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/27 16:01:48 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	size;

	if (!*needle || needle == '\0' || ft_strlen((char *) needle) == 0)
		return ((char *) haystack);
	if (ft_strlen((char *) needle) > ft_strlen((char *) haystack) || len == 0)
		return (NULL);
	size = 0;
	i = 0;
	while (haystack[size] != '\0' && size < len)
	{
		if (haystack[size] == needle[0])
		{
			while (needle[i] && haystack[size + i] && size + i < len \
				&& haystack[size + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *) haystack + size);
		}
		size++;
	}
	return (0);
}
