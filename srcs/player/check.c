/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:49:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 16:31:13 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_half_step_x(t_game *game, int y)
{
	int	x_1;
	int	x_2;

	x_1 = game->player.x;
	if ((game->player.f_x + game->map.desloc_x) > game->player.x)
		x_2 = x_1 + 1;
	else
		x_2 = x_1 - 1;
	if (game->map.array[y][x_1] == WALL || game->map.array[y][x_2] == WALL)
		return (1);
	return (0);
}

int	check_collision_y(t_game *game, int move)
{
	int		y;
	int		half_step_y;
	int		half_step_x;
	double	y_x_global[2];

	y_x_global[0] = game->player.f_y + game->map.desloc_y;
	y_x_global[1] = game->player.f_x + game->map.desloc_x;
	half_step_y = !(aprox(y_x_global[0], game->player.y));
	half_step_x = !(aprox(y_x_global[1], game->player.x));
	if (half_step_y)
		return (0);
	if (move == UP)
		y = -1;
	else
		y = 1;
	y += game->player.y;
	if (half_step_x && check_half_step_x(game, y))
		return (1);
	else
	{
		if (game->map.array[y][game->player.x] == WALL)
			return (1);
	}
	return (0);
}

static int	check_half_step_y(t_game *game, int x)
{
	int	y_1;
	int	y_2;

	y_1 = game->player.y;
	if (game->player.f_y + game->map.desloc_y >= game->player.y)
		y_2 = y_1 + 1;
	else
		y_2 = y_1 - 1;
	if (game->map.array[y_1][x] == WALL || game->map.array[y_2][x] == WALL)
		return (1);
	return (0);
}

int	check_collision_x(t_game *game, int move)
{
	int		x;
	int		half_step_y;
	int		half_step_x;
	double	y_x_global[2];

	y_x_global[0] = game->player.f_y + game->map.desloc_y;
	y_x_global[1] = game->player.f_x + game->map.desloc_x;
	half_step_y = !(aprox(y_x_global[0], game->player.y));
	half_step_x = !(aprox(y_x_global[1], game->player.x));
	if (half_step_x)
		return (0);
	if (move == LEFT)
		x = -1;
	else
		x = 1;
	x += game->player.x;
	if (half_step_y && check_half_step_y(game, x))
		return (1);
	else
	{
		if (game->map.array[game->player.y][x] == WALL)
			return (1);
	}
	return (0);
}
