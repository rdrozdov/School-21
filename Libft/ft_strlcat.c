/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:44:43 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:27:37 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	src_size;
	size_t	dst_size;

	dst_size = 0;
	src_size = ft_strlen(src);
	while (dst[dst_size] && dst_size < n)
		dst_size++;
	if (dst_size == n)
		return (src_size + n);
	if (n - dst_size > src_size)
		ft_strlcpy(&dst[dst_size], src, src_size + 1);
	else
		ft_strlcpy(&dst[dst_size], src, n - dst_size);
	return (src_size + dst_size);
}
