/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:38:57 by gcolene           #+#    #+#             */
/*   Updated: 2021/11/09 14:56:24 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*copy_elem;

	if (!lst)
		return ;
	while (*lst)
	{
		copy_elem = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = copy_elem;
	}
	*lst = NULL;
}
