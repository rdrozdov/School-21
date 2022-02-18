/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:43:48 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/16 17:01:31 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_variables(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_game("MLX didn't initialized");
	data->move_count = 0;
	data->map.array = malloc(sizeof(char *));
	if (!data->map.array)
		exit_game("Didn't allocate memory for map array");
	data->map.array[0] = NULL;
	data->map.rows = 0;
}

static void	init_game_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->map.columns * PLATE_SIZE, \
		data->map.rows * PLATE_SIZE, "so_long_project");
	if (!data->win)
		exit_game("MLX couldn't create a new window");
	data->frame_buf = mlx_new_image(data->mlx, data->map.columns * \
		PLATE_SIZE, data->map.rows * PLATE_SIZE);
	data->addr = mlx_get_data_addr(data->frame_buf, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit_game("Incorrect number of arguments.\n" \
		"Try './so_long maps/1.ber'");
	init_game_variables(&data);
	read_map_file(argv[1], &(data.map));
	check_map_values(&data);
	sprites_load(&data);
	init_game_window(&data);
	create_screen(&data);
	setup_event_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
