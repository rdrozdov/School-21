/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:18:43 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/16 17:10:39 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_value(t_data *data, int x, int y)
{
	if (data->map.array[x][y] == PLAYER)
	{
		data->player.row = x;
		data->player.column = y;
		(data->player_count)++;
	}
	if (data->map.array[x][y] == EXIT)
		(data->exit_count)++;
	if (data->map.array[x][y] == COLLECTIBLE)
		data->collectible.count++;
	if (!ft_strchr("01CPE", data->map.array[x][y]))
		exit_game("Invalid character in map");
	if (x == 0 || y == 0 || x == data->map.rows - 1 \
	|| y == data->map.columns - 1)
		if (data->map.array[x][y] != WALL)
			exit_game("Walls didn't surround the map");
}

int	check_map_values(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->player_count = 0;
	data->collectible.count = 0;
	data->exit_count = 0;
	while (data->map.rows > x)
	{
		y = 0;
		while (data->map.columns > y)
		{
			check_map_value(data, x, y);
			y++;
		}
		x++;
	}
	if (data->exit_count < 1 || data->collectible.count < 1 \
	|| data->player_count != 1)
		exit_game("Numbers of values on the map is incorrect");
	return (0);
}

int	check_map_lines_length(char *new_line, int expected_length)
{
	int	line_length;

	line_length = ft_strlen(new_line);
	if (ft_strchr(new_line, '\n'))
		line_length -= 1;
	return (line_length == expected_length);
}

int	check_map_file_extension(char *map_path)
{
	size_t	path_length;
	char	*ber;

	path_length = ft_strlen(map_path);
	ber = ft_strnstr(map_path, ".ber", path_length);
	if (ber)
	{
		if (ber == (map_path + path_length - 4))
			return (1);
	}
	exit_game("Invalid map file. Expected '.ber' extension.");
	return (0);
}
