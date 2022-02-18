/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:27:25 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:48:14 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	while (count && *str1 && (*str1 == *str2))
	{
		++str1;
		++str2;
		--count;
	}
	if (count == 0)
		return (0);
	else
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
