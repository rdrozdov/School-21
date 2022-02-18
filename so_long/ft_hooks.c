/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:33:29 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/18 13:21:22 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_action(t_data *data, int row, int column)
{
	if (data->map.array[row][column] != WALL)
	{
		if (data->map.array[row][column] == COLLECTIBLE)
		{
			data->collectible.count--;
			data->map.array[row][column] = GROUND;
		}
		if (data->map.array[row][column] == EXIT)
		{
			if (data->collectible.count == 0)
			{
				ft_printf("Moves: %d\n", ++data->move_count);
				ft_printf("\nYou won with %d moves!", data->move_count);
				exit_game(NULL);
			}
		}
		ft_printf("Moves: %d\n", ++data->move_count);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == UP)
		if (check_action(data, data->player.row - 1, data->player.column))
			data->player.row -= 1;
	if (keycode == DOWN)
		if (check_action(data, data->player.row + 1, data->player.column))
			data->player.row += 1;
	if (keycode == LEFT)
		if (check_action(data, data->player.row, data->player.column - 1))
			data->player.column -= 1;
	if (keycode == RIGHT)
		if (check_action(data, data->player.row, data->player.column + 1))
			data->player.column += 1;
	mlx_clear_window(data->mlx, data->win);
	create_screen(data);
	return (0);
}

void	setup_event_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, (1L << 17), exit_game, NULL);
}
