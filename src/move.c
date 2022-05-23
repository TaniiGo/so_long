/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:00:38 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/21 19:45:17 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void	move_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	game->player.y -= 32;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.player, game->player.x, game->player.y);
	ft_printf("Number of movements: %d\n", ++game->movement_num);
}

void	move_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	game->player.x -= 32;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.player, game->player.x, game->player.y);
	ft_printf("Number of movements: %d\n", ++game->movement_num);
}

void	move_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	game->player.y += 32;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.player, game->player.x, game->player.y);
	ft_printf("Number of movements: %d\n", ++game->movement_num);
}

void	move_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	game->player.x += 32;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.tile, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.player, game->player.x, game->player.y);
	ft_printf("Number of movements: %d\n", ++game->movement_num);
}

void	move_player(char key, t_game *game)
{
	if (key == 'w')
		if (is_movable(key, game))
			move_up(game);
	if (key == 'a')
		if (is_movable(key, game))
			move_left(game);
	if (key == 's')
		if (is_movable(key, game))
			move_down(game);
	if (key == 'd')
		if (is_movable(key, game))
			move_right(game);
}
