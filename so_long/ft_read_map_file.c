/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:33:21 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/16 16:49:44 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	add_line_to_map(t_map *map, char *new_line)
{
	char	**new_map;
	size_t	i;

	i = 0;
	map->rows += 1;
	new_map = malloc(sizeof(char *) * (map->rows + 1));
	if (!new_map)
		exit_game("Didn't allocate memory for new_map");
	while (map->array[i])
	{
		new_map[i] = map->array[i];
		i++;
	}
	new_map[i] = new_line;
	new_map[i + 1] = NULL;
	free(map->array);
	map->array = new_map;
	return (0);
}

int	read_map_file(char *path, t_map *map)
{
	int		fd;
	char	*new_line;

	check_map_file_extension(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_game("Didn't open map file");
	new_line = get_next_line(fd);
	if (!new_line)
		exit_game("Didn't read from map file");
	map->columns = ft_strlen(new_line) - 1;
	while (new_line)
	{
		if (!check_map_lines_length(new_line, map->columns))
			exit_game("Map is not rectangular");
		add_line_to_map(map, new_line);
		new_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
