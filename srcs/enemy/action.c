/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/08 22:45:00 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	enemy_move(t_game *game, t_enemy *enemy)
{
	double	position[2];
	double	direction[2];

	f_copy_vetor(position, enemy->position);
	f_copy_vetor(direction, enemy->direction);
	f_multi_vetor(direction, game->enemy_speed);
	f_sum_vetor(position, direction);
	if (!check_collision(game, enemy->direction, position))
		f_sum_vetor(enemy->position, direction);
	enemy->delay += 1;
	if (enemy->delay > FRAMES)
	{
		enemy->walk_frame += 1;
		if (enemy->walk_frame > 2)
			enemy->walk_frame = 0;
		enemy->delay = 0;
	}
}

void	move_enemies(t_game *game)
{
	t_enemy	*enemy;
	int		move;

	enemy = game->enemies;
	while (enemy)
	{
		enemy_move(game, enemy);
		enemy->steps += 1;
		if (enemy->steps >= 100)
		{
			move = my_rand() % 4;
			if (move == 0)
				f_new_vetor(enemy->direction, -1, 0);
			else if (move == 1)
				f_new_vetor(enemy->direction, 1, 0);
			else if (move == 2)
				f_new_vetor(enemy->direction, 0, -1);
			else if (move == 3)
				f_new_vetor(enemy->direction, 0, 1);
			enemy->steps = 0;
		}
		enemy = enemy->next;
	}
	check_enemy_collition(game);
}

void	move_enemy(t_game *game)
{
	double		*direction;
	t_enemy		*enemy;
	double		player_pos[2];

	enemy = game->enemy_found;
	f_copy_vetor(player_pos, game->player.position);
	f_sum_vetor(player_pos, game->map.desloc);
	direction = enemy->direction;
	if (direction[1] == 1 && enemy->position[1] < player_pos[1] - 1)
		enemy->position[1] += game->enemy_speed[1];
	if (direction[1] == -1 && enemy->position[1] > player_pos[1] + 1)
		enemy->position[1] -= game->enemy_speed[1];
	if (direction[0] == 1 && enemy->position[0] < player_pos[0] - 1)
		enemy->position[0] += game->enemy_speed[0];
	if (direction[0] == -1 && enemy->position[0] > player_pos[0] + 1)
		enemy->position[0] -= game->enemy_speed[0];
}
