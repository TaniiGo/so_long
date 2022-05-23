/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:58:44 by keitanig          #+#    #+#             */
/*   Updated: 2022/05/21 19:45:41 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	handle_error(t_game *game, char *message)
{
	ft_printf("Error\n%s\n", message);
	free_game(game);
	exit(EXIT_FAILURE);
}
