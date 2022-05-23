/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:37:13 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/21 19:44:46 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../inc/so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

bool	is_valid_file_name(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (false);
	if (file_name[len - 5] == '/' || ft_strncmp(&file_name[len - 4],
			".ber", 4) != 0)
		return (false);
	return (true);
}

size_t	map_line_len(char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\n' && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	get_map_size(t_game *game)
{
	size_t	y;

	game->map_width = map_line_len(game->map[0]);
	y = 0;
	while (game->map[y] != NULL)
	{
		game->map_height++;
		y++;
	}
}

bool	is_map_rectangular(t_game *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1')
			return (false);
		x++;
	}
	x = 0;
	while (x < game->map_width)
	{
		if (game->map[game->map_height - 1][x] != '1')
			return (false);
		x++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1')
			return (false);
		y++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][game->map_width - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

void	read_map_file(t_game *game, char *file_name)
{
	int		fd;
	size_t	i;

	game->map = (char **)ft_calloc(1000, sizeof(char *));
	if (game->map == NULL)
		handle_error(game, ERR_MEMORY);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		handle_error(game, ERR_OPEN);
	i = 0;
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
	}
	if (close(fd) == -1)
		handle_error(game, ERR_CLOSE);
}
