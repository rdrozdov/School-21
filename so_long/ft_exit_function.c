/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:43 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/16 16:45:21 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(char *error_message)
{
	if (error_message)
	{
		ft_printf_fd(STDERR_FILENO, "Error!\n%s\n", error_message);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
