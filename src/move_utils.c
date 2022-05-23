/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:04:41 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/21 19:45:26 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_next_space(char *space, t_game *game)
{
	if (*space == '1')
		return (0);
	if (*space == 'C')
	{
		game->collect_num--;
		*space = '0';
		return (1);
	}
	if (*space == 'E')
	{
		if (game->collect_num == 0)
		{
			ft_printf("Number of movements: %d\n", ++game->movement_num);
			free_and_exit(game);
		}
		return (0);
	}
	return (1);
}

int	is_movable(char key, t_game *game)
{
	size_t	x;
	size_t	y;

	x = game->player.x / 32;
	y = game->player.y / 32;
	if (key == 'w')
		return (check_next_space(&game->map[y - 1][x], game));
	if (key == 'a')
		return (check_next_space(&game->map[y][x - 1], game));
	if (key == 's')
		return (check_next_space(&game->map[y + 1][x], game));
	if (key == 'd')
		return (check_next_space(&game->map[y][x + 1], game));
	return (0);
}
