/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:17 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/16 16:53:05 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*find_plate_img(t_data *data, int y, int x)
{
	if (data->map.array[x][y] == WALL)
		return (data->walls);
	else if (data->map.array[x][y] == COLLECTIBLE)
		return (data->collectible.img);
	else if (data->map.array[x][y] == EXIT)
		return (data->exit_img);
	return (0);
}

static void	put_floor_images(t_data *data, int y, int x)
{
	void	*plate_img;

	mlx_put_image_to_window(data->mlx, data->win, data->floor, \
	y * PLATE_SIZE, x * PLATE_SIZE);
	plate_img = find_plate_img(data, y, x);
	if (plate_img)
		mlx_put_image_to_window(data->mlx, data->win, plate_img, \
		y * PLATE_SIZE, x * PLATE_SIZE);
}

int	create_screen(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.rows)
	{
		y = 0;
		while (y < data->map.columns)
		{
			put_floor_images(data, y, x);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.img, \
	data->player.column * PLATE_SIZE, data->player.row * PLATE_SIZE);
	return (0);
}
