/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:19:28 by gcolene           #+#    #+#             */
/*   Updated: 2021/10/05 17:46:07 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int a)
{
	if ((a <= 90 && a >= 65) || (a <= 122 && a >= 97))
		return (a);
	return (0);
}
