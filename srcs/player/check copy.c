/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:49:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 23:05:35 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_collision_y(t_game *game, int move)
{
	int	y;
	int	x_1;
	int	x_2;
	int	half_step_x;
	int	half_step_y;

	if (move == UP)
		y = -1;
	else
		y = 1;
	half_step_x = !(my_abs(game->player.f_x - game->player.x) < APROX_MIN);
	half_step_y = !(my_abs(game->player.f_y - game->player.y) < APROX_MIN);
	if (half_step_y)
		return (0);
	y += ((int) game->player.y + game->map.desloc_y);
	x_1 = (int) game->player.f_x + game->map.desloc_x;
	if (half_step_x)
		x_2 = x_1 + 1;
	else
		x_2 = x_1;
	printf("x_1 = %d, x_2 = %d\n", x_1, x_2);
	printf("half %d\n", half_step_x);
	if (game->map.array[y][x_1] == WALL || game->map.array[y][x_2] == WALL)
		return (1);
	return (0);
}

int	check_collision_x(t_game *game, int move)
{
	int	x;
	int	y_1;
	int	y_2;
	int	half_step_x;
	int	half_step_y;

	half_step_x = !(my_abs(game->player.f_x - game->player.x) < APROX_MIN);
	half_step_y =  !(my_abs(game->player.f_y - game->player.y) < APROX_MIN);
	if (half_step_x)
		return (0);
	if (move == LEFT)
		x = -1;
	else
		x = 1;
	x += (game->player.x + game->map.desloc_x);
	y_1 = (int) game->player.f_y + game->map.desloc_y;
	if (half_step_y)
		y_2 = y_1 + 1;
	else
		y_2 = y_1;
	printf("y_1 = %d, y_2 = %d\n", y_1, y_2);
	printf("half %d\n", half_step_y);
	if (game->map.array[y_1][x] == WALL || game->map.array[y_2][x] == WALL)
		return (1);
	return (0);
}
