/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:34:10 by gcolene           #+#    #+#             */
/*   Updated: 2022/02/16 17:08:31 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# include "libft/MyLibft/libft.h"
# include "libft/ft_printf.h"
# include "mlx/mlx.h"

# define PLATE_SIZE 32

typedef enum e_tiletype
{
	GROUND = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef enum e_keycode
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
}	t_keycode;

typedef struct s_player
{
	void	*img;
	int		row;
	int		column;
}	t_player;

typedef struct s_collectible
{
	void	*img;
	int		count;
}	t_collectible;

typedef struct s_map
{
	char	**array;
	int		rows;
	int		columns;
}	t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*floor;
	void			*walls;
	void			*exit_img;
	void			*frame_buf;
	int				move_count;
	int				exit_count;
	int				player_count;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*addr;
	t_player		player;
	t_collectible	collectible;
	t_map			map;
}	t_data;

char	*get_next_line(int fd);
int		read_map_file(char *path, t_map *map);
int		check_map_file_extension(char *map_path);
int		check_map_lines_length(char *new_line, int expected_length);
int		check_map_values(t_data *data);
int		sprites_load(t_data *data);
int		create_screen(t_data *data);
void	*find_plate_img(t_data *data, int x, int y);
void	setup_event_hooks(t_data *data);
int		key_hook(int keycode, t_data *data);
int		exit_game(char *error_message);

#endif