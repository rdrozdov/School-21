/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:16:59 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:17:03 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*serach_str;
	char	*result_str;

	serach_str = (char *)str;
	result_str = 0;
	i = 0;
	while (serach_str[i])
	{
		if (serach_str[i] == (char)ch)
			result_str = serach_str + i;
		i++;
	}
	if (ch == '\0')
		return (&serach_str[i]);
	return (result_str);
}
