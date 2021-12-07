/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 12:59:27 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	move_y(t_game *game, int move, t_enemy *enemy)
{
	int		direction;

	if (move == DOWN)
		direction = 1;
	else
		direction = -1;
	enemy->f_y += (game->enemy_vel * direction);
	return (direction);
}

static int	move_x(t_game *game, int move, t_enemy *enemy)
{
	int		direction;

	if (move == RIGHT)
		direction = 1;
	else
		direction = -1;
	enemy->f_x += (game->enemy_vel * direction);
	return (direction);
}

void	enemy_move(t_game *game, int move, t_enemy *enemy)
{
	int		direction;
	double	next_block;

	if ((move == LEFT || move == RIGHT) && !enemy_collision_x(game, move, enemy))
	{
		direction = move_x(game, move, enemy);
		next_block = enemy->x + direction;
		if (aprox(next_block, enemy->f_x))
			enemy->x += direction;
	}
	if ((move == DOWN || move == UP) && !enemy_collision_y(game, move, enemy))
	{
		direction = move_y(game, move, enemy);
		next_block = enemy->y + direction;
		if (aprox(next_block, enemy->f_y))
			enemy->y += direction;
	}
}

void	move_enemies(t_game *game)
{
	t_enemy	*enemy;
	int		move;

	enemy = game->enemies;
	while (enemy)
	{
		enemy_move(game, enemy->direction, enemy);
		enemy->steps += 1;
		if (enemy->steps >= 100)
		{
			move = my_rand() % 4;
			if (move == 0)
				enemy->direction = LEFT;
			else if (move == 1)
				enemy->direction = RIGHT;
			else if (move == 2)
				enemy->direction = UP;
			else if (move == 3)
				enemy->direction = DOWN;
			enemy->steps = 0;
		}
		enemy = enemy->next;
	}
	check_enemy_collition(game);
}

void	move_enemy(t_game *game)
{
	int			direction;
	t_enemy		*enemy;
	t_player	player;

	enemy = game->enemy_found;
	player = game->player;
	direction = enemy->direction;
	if (direction == DOWN && enemy->f_y < player.f_y - 1 + game->map.desloc_y)
		enemy->f_y += game->enemy_vel;
	if (direction == UP && enemy->f_y > player.f_y + 1 + game->map.desloc_y)
		enemy->f_y -= game->enemy_vel;
	if (direction == RIGHT && enemy->f_x < player.f_x - 1 + game->map.desloc_x)
		enemy->f_x += game->enemy_vel;
	if (direction == LEFT && enemy->f_x > player.f_x + 1 + game->map.desloc_x)
		enemy->f_x -= game->enemy_vel;
}
