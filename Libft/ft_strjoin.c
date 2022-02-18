/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:59:05 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:27:56 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		count1;
	int		count2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	count1 = 0;
	str = malloc (len1 + len2 + 1);
	if (!str)
		return (NULL);
	while (count1 < len1)
	{
		str[count1] = s1[count1];
		count1++;
	}
	count2 = 0;
	while (count2 < len2)
		str[count1++] = s2[count2++];
	str[count1] = '\0';
	return (str);
}
