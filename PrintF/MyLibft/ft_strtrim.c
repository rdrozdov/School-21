/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:34:19 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:16:17 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		count;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	count = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen((char *)s1);
	while (len > 0 && ft_strrchr(set, s1[len]))
		len--;
	str = ft_substr(s1, count, len - count + 1);
	return (str);
}
