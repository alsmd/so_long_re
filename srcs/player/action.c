/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 18:51:47 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	change_frame(t_game *game, int move)
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

static int	move_y(t_game *game, int move)
{
	double	new_pos;
	int		direction;

	if (move == DOWN)
	{
		direction = 1;
		new_pos = game->map.desloc_y + (game->vel * direction) + game->height;
		if (game->player.f_y >= game->height / 2 && new_pos <= game->map.height)
			game->map.desloc_y += (game->vel * direction);
		else
			game->player.f_y += (game->vel * direction);
	}
	else
	{
		direction = -1;
		if (game->player.f_y < game->height / 2 && game->map.desloc_y > 0)
			game->map.desloc_y += (game->vel * direction);
		else
			game->player.f_y += (game->vel * direction);
	}
	return (direction);
}

static int	move_x(t_game *game, int move)
{
	double	new_pos;
	int		direction;

	if (move == RIGHT)
	{
		direction = 1;
		new_pos = game->map.desloc_x + (game->vel * direction) + game->width;
		if (game->player.f_x >= game->width / 2 && new_pos <= game->map.width)
			game->map.desloc_x += (game->vel * direction);
		else
			game->player.f_x += (game->vel * direction);
	}
	else
	{
		direction = -1;
		if (game->player.f_x < game->height / 2 && game->map.desloc_x > 0)
			game->map.desloc_x += (game->vel * direction);
		else
			game->player.f_x += (game->vel * direction);
	}
	return (direction);
}

void	player_move(t_game *game, int move)
{
	int		direction;
	double	next_block;

	if ((move == LEFT || move == RIGHT) && !check_collision_x(game, move))
	{
		direction = move_x(game, move);
		next_block = game->player.x + direction;
		if (aprox(next_block, game->player.f_x + game->map.desloc_x))
		{
			game->map.array[game->player.y][game->player.x] = FLOOR;
			game->player.x += direction;
		}
	}
	if ((move == DOWN || move == UP) && !check_collision_y(game, move))
	{
		direction = move_y(game, move);
		next_block = game->player.y + direction;
		if (aprox(next_block, game->player.f_y + game->map.desloc_y))
		{
			game->map.array[game->player.y][game->player.x] = FLOOR;
			game->player.y += direction;
		}
	}
	game->map.array[game->player.y][game->player.x] = PLAYER;
	check_enemy_collition(game);
}
