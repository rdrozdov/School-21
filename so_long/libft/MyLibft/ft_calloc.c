/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:19:25 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/26 17:40:36 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	int		i;

	i = 0;
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	if (sizeof(count) == 0)
		return (0);
	ft_memset(temp, 0, size * count);
	return (temp);
}
