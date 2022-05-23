/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:43:58 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/23 16:53:40 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/so_long.h"
#include <stdio.h>
#include <stdbool.h>

void	load_img(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.tile = mlx_xpm_file_to_image(game->mlx,
			IMG_TILE, &img_width, &img_height);
	if (game->img.tile == NULL)
		handle_error(game, ERR_MLX);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			IMG_WALL, &img_width, &img_height);
	if (game->img.wall == NULL)
		handle_error(game, ERR_MLX);
	game->img.collect = mlx_xpm_file_to_image(game->mlx,
			IMG_COLLECT, &img_width, &img_height);
	if (game->img.collect == NULL)
		handle_error(game, ERR_MLX);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			IMG_EXIT, &img_width, &img_height);
	if (game->img.exit == NULL)
		handle_error(game, ERR_MLX);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			IMG_PLAYER, &img_width, &img_height);
	if (game->img.player == NULL)
		handle_error(game, ERR_MLX);
}

int	key_check(int key_code, t_game *game)
{
// バツボタン押して終了する際の条件も追加
	if (key_code == KEY_ESC)
		free_and_exit(game);
	else if (key_code == KEY_W)
		move_player('w', game);
	else if (key_code == KEY_A)
		move_player('a', game);
	else if (key_code == KEY_S)
		move_player('s', game);
	else if (key_code == KEY_D)
		move_player('d', game);
	return (0);
}

void	get_map_info(t_game *game, char *file_name)
{
	if (is_valid_file_name(file_name) == false)
		handle_error(game, ERR_FILENAME);
	read_map_file(game, file_name);
	if (!game->map)
		handle_error(game, ERR_READ);
	get_map_size(game);
	if (is_map_rectangular(game) == false)
		handle_error(game, ERR_MAP);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit(EXIT_FAILURE);
	ft_memset(&game, 0, sizeof(t_game));
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		handle_error(&game, ERR_MLX);
	get_map_info(&game, av[1]);
	game.win = mlx_new_window(game.mlx, 32 * game.map_width,
			32 * game.map_height, "so_long");
	load_img(&game);
	render_map(&game);
	if (game.player_num != 1 || game.collect_num == 0 || game.exit_num != 1)
		return (1);
	mlx_key_hook(game.win, key_check, &game);
	mlx_loop(game.mlx);
	return (0);
}
