/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:49:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 00:52:59 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_half_step_x(t_game *game, int y, t_enemy *enemy)
{
	int	x_1;
	int	x_2;

	x_1 = enemy->x;
	if ((enemy->f_x) > enemy->x)
		x_2 = x_1 + 1;
	else
		x_2 = x_1 - 1;
	if (game->map.array[y][x_1] == WALL || game->map.array[y][x_2] == WALL)
		return (1);
	return (0);
}

int	enemy_collision_y(t_game *game, int move, t_enemy *enemy)
{
	int		y;
	int		half_step_y;
	int		half_step_x;

	half_step_y = !(aprox(enemy->f_y, enemy->y));
	half_step_x = !(aprox(enemy->f_x, enemy->x));
	if (half_step_y)
		return (0);
	if (move == UP)
		y = -1;
	else
		y = 1;
	y += enemy->y;
	if (half_step_x && check_half_step_x(game, y, enemy))
		return (1);
	else
	{
		if (game->map.array[y][enemy->x] == WALL)
			return (1);
	}
	return (0);
}

static int	check_half_step_y(t_game *game, int x, t_enemy *enemy)
{
	int	y_1;
	int	y_2;

	y_1 = enemy->y;
	if (enemy->f_y >= enemy->y)
		y_2 = y_1 + 1;
	else
		y_2 = y_1 - 1;
	if (game->map.array[y_1][x] == WALL || game->map.array[y_2][x] == WALL)
		return (1);
	return (0);
}

int	enemy_collision_x(t_game *game, int move, t_enemy *enemy)
{
	int		x;
	int		half_step_y;
	int		half_step_x;
	double	y_x_global[2];

	half_step_y = !(aprox(enemy->f_y, enemy->y));
	half_step_x = !(aprox(enemy->f_x, enemy->x));
	if (half_step_x)
		return (0);
	if (move == LEFT)
		x = -1;
	else
		x = 1;
	x += enemy->x;
	if (half_step_y && check_half_step_y(game, x, enemy))
		return (1);
	else
	{
		if (game->map.array[enemy->y][x] == WALL)
			return (1);
	}
	return (0);
}

int	player_collition_on_range(t_game *game, double x, double y)
{
	if (aprox(x, ((game->player.f_x * BLOCK_SIZE))) && \
		aprox(y, ((game->player.f_y * BLOCK_SIZE))))
		return (1);
	if (aprox(x, game->player.f_x * BLOCK_SIZE + BLOCK_SIZE - 1) && \
		aprox(y, game->player.f_y * BLOCK_SIZE))
		return (1);
	if (aprox(x, game->player.f_x * BLOCK_SIZE) && \
		aprox(y, game->player.f_y * BLOCK_SIZE + BLOCK_SIZE - 1))
		return (1);
	if (aprox(x, game->player.f_x * BLOCK_SIZE + BLOCK_SIZE - 1) && \
		aprox(y, game->player.f_y * BLOCK_SIZE + BLOCK_SIZE - 1))
		return (1);
	return (0);
}
