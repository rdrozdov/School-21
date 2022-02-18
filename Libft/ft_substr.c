/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:41:52 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 19:52:55 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	return_term(char *str, char const *s, \
unsigned int start, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len && start < (unsigned int) ft_strlen((char *) s) \
	&& s[start])
	{
		str[count] = s[start++];
		count++;
	}
	str[count] = '\0';
	return (*str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size_m;

	str = (char *)s;
	if (!s)
	{
		return (NULL);
	}
	if (start > ft_strlen(s) || len == 0)
	{
		str = (char *) malloc (1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen(s + start) >= len)
		size_m = len;
	else
		size_m = ft_strlen(s);
	str = (char *) malloc (size_m + 1);
	if (!str)
		return (NULL);
	return_term(str, s, start, len);
	return (str);
}
