/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:06:42 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/21 19:45:03 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_objects(t_game *game, size_t y, size_t x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
	{
		game->collect_num++;
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collect, x * 32, y * 32);
	}
	else if (game->map[y][x] == 'E')
	{
		game->exit_num++;
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * 32, y * 32);
	}
	else if (game->map[y][x] == 'P')
	{
		game->player_num++;
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * 32, y * 32);
		game->player.x = x * 32;
		game->player.y = y * 32;
	}
}

void	render_map(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	len;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			len = map_line_len(game->map[y]);
			if (len != game->map_width)
				handle_error(game, ERR_MAP);
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.tile, x * 32, y * 32);
			if (game->map[y][x] != '0')
				render_objects(game, y, x);
			x++;
		}
		y++;
	}
}
