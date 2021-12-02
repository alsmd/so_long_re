/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:49:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 03:54:25 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_collision_y(t_game *game, int move)
{
	int	y;
	int	x_1;
	int	x_2;

	if (move == UP)
		y = -1;
	else
		y = 1;
	if (game->player.f_y - game->player.y != 0)
		return (0);
	y += ((int) game->player.f_y);
	x_1 = (int) game->player.f_x;
	x_2 = (int) (game->player.f_x + 0.5f);
	if (game->map.array[y][x_1] == WALL || game->map.array[y][x_2] == WALL)
		return (1);
	return (0);
}

int	check_collision_x(t_game *game, int move)
{
	int	x;
	int	y_1;
	int	y_2;

	if (move == LEFT)
		x = -1;
	else
		x = 1;
	if (game->player.f_x - game->player.x != 0)
		return (0);
	x += ((int) game->player.f_x);
	y_1 = (int) game->player.f_y;
	y_2 = (int) (game->player.f_y + 0.5);
	if (game->map.array[y_1][x] == WALL || game->map.array[y_2][x] == WALL)
		return (1);
	return (0);
}
