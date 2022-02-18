/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:54:42 by gcolene           #+#    #+#             */
/*   Updated: 2021/11/15 21:39:12 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		count1;
	int		count2;

	if (!s2)
		return (NULL);
	count1 = 0;
	str = (char *)malloc (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[count1])
	{
		str[count1] = s1[count1];
		count1++;
	}
	count2 = 0;
	while (s2[count2])
		str[count1++] = s2[count2++];
	str[count1] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*ft_strchr(char *str, int ch)
{
	int		i;
	char	*serach_str;

	if (!str)
		return (NULL);
	serach_str = (char *)str;
	i = 0;
	while (serach_str[i])
	{
		if (serach_str[i] == (unsigned char)ch)
			return (serach_str + i);
		i++;
	}
	if (ch == '\0')
		return (&serach_str[i]);
	return (NULL);
}

static char	return_term(char *str, char *s, \
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size_m;

	str = (char *)s;
	if (!s)
		return (NULL);
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
