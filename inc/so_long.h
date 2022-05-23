/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:50:52 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/21 19:57:43 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct	s_player {
	size_t	x;
	size_t	y;
}				t_player;

typedef struct	s_img {
	void	*tile;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
}				t_img;

typedef struct	s_game {
	void		*mlx;
	void		*win;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	t_img		img;
	t_player	player;
	size_t		collect_num;
	size_t		player_num;
	size_t		exit_num;
	int			movement_num;
}				t_game;

/*** key code ***/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

/*** path img ***/
# define IMG_TILE "img/tile3232.xpm"
# define IMG_WALL "img/wall.xpm"
# define IMG_COLLECT "img/collect.xpm"
# define IMG_EXIT "img/tama.xpm"
# define IMG_PLAYER "img/koto_sprite.xpm"

/*** error message ***/
# define ERR_MLX "mlx function failed."
# define ERR_FILENAME "File name needs to end with .ber extension."
# define ERR_MEMORY "Memory allocation failed."
# define ERR_OPEN "Failed to open file."
# define ERR_CLOSE "Failed to close file."
# define ERR_READ "Failed to read file."
# define ERR_MAP "Map is not collect."

/*** map.c ***/
bool	is_valid_file_name(char *file_name);
void	read_map_file(t_game *game, char *file_name);
void	get_map_size(t_game *game);
size_t	map_line_len(char *str);
bool	is_map_rectangular(t_game *game);

/*** render.c ***/
void	render_objects(t_game *game, size_t y, size_t x);
void	render_map(t_game *game);

/*** move.c ***/
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_player(char key, t_game *game);

/*** move_utils.c ***/
int		check_next_space(char *space, t_game *game);
int		is_movable(char key, t_game *game);

/*** error.c ***/
void	handle_error(t_game *game, char *message);

/*** free.c ***/
void	free_map(char **map);
void	free_game(t_game *game);
void	free_and_exit(t_game *game);

#endif