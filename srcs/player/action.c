/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/03 00:03:28 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	change_frame(t_game *game, int move)
{
	game->player.delay += 1;
	if (game->player.walk_frame < 3)
		game->player.walk_frame += 1;
	else
		game->player.walk_frame = 1;
	if (move == DOWN)
		game->player.direction = DOWN;
	if (move == UP)
		game->player.direction = UP;
	if (move == LEFT)
		game->player.direction = LEFT;
	if (move == RIGHT)
		game->player.direction = RIGHT;
}

static void	move_y(t_game *game, int move)
{
	double	next_block;
	int		direction;

	if (move == DOWN)
		direction = 1;
	else
		direction = -1;
	game->player.f_y += (game->vel * direction);
	next_block = game->player.y + direction;
	if (my_abs(next_block - game->player.f_y) < APROX_MIN)
	{
		game->map.array[game->player.y][game->player.x] = FLOOR;
		game->player.y += direction;
	}
}


static void	move_x(t_game *game, int move)
{
	int		direction;
	double	next_block;
	
	if (move == RIGHT)
		direction = 1;
	else
		direction = -1;
	game->player.f_x += (game->vel * direction);
	next_block = game->player.x + direction;
	if (my_abs(next_block - game->player.f_x) < APROX_MIN)
	{
		game->map.array[game->player.y][game->player.x] = FLOOR;
		game->player.x += direction;
	}
}

void	player_move(t_game *game, int move)
{
	change_frame(game, move);
	if ((move == LEFT || move == RIGHT) && !check_collision_x(game, move))
		move_x(game, move);
	if ((move == DOWN || move == UP) && !check_collision_y(game, move))
		move_y(game, move);
	game->map.array[game->player.y][game->player.x] = PLAYER;
}
