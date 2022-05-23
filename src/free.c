/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:57:22 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/21 19:45:54 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->img.tile)
		mlx_destroy_image(game->mlx, game->img.tile);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.collect)
		mlx_destroy_image(game->mlx, game->img.collect);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
	{
		// mlx_destroy_display(game->mlx);
		// mlx_loop_end(game->mlx);
		free(game->mlx);
	}
}

void	free_and_exit(t_game *game)
{
	free_game(game);
	system("leaks so_long");
	exit(EXIT_SUCCESS);
}
