/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:54:58 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/16 16:56:35 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	floor_n_walls_load(t_data *data)
{
	int	width;
	int	height;

	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/Floor2.xpm", \
	&width, &height);
	if (!data->floor)
		exit_game("Didn't load floor");
	data->walls = mlx_xpm_file_to_image(data->mlx, "./assets/Wall.xpm", \
	&width, &height);
	if (!data->walls)
		exit_game("Didn't load walls");
}

static void	player_load(t_data *data)
{
	int	width;
	int	height;

	data->player.img = mlx_xpm_file_to_image(data->mlx, "./assets/Player1.xpm", \
	&width, &height);
	if (!data->player.img)
		exit_game("Didn't load player");
}

static void	collectible_load(t_data *data)
{
	int	width;
	int	height;

	data->collectible.img = mlx_xpm_file_to_image(data->mlx, \
	"./assets/Collectible.xpm", &width, &height);
	if (!data->collectible.img)
		exit_game("Didn't load collectible item");
}

static void	exit_load(t_data *data)
{
	int	width;
	int	height;

	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./assets/Exit.xpm", \
	&width, &height);
	if (!data->exit_img)
		exit_game("Didn't load exit");
}

int	sprites_load(t_data *data)
{
	floor_n_walls_load(data);
	player_load(data);
	collectible_load(data);
	exit_load(data);
	return (0);
}
