/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:12:03 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:29:41 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*serach_str;

	serach_str = (char *)str;
	i = 0;
	while (serach_str[i])
	{
		if (serach_str[i] == (char)ch)
			return (serach_str + i);
		i++;
	}
	if (ch == '\0')
		return (&serach_str[i]);
	return (0);
}
