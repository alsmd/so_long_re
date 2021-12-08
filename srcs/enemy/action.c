/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/08 17:48:04 by flda-sil         ###   ########.fr       */
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
	printf("enemy x %f, enemy y %f\n", position[0], position[1]);
	if (!check_collision(game, enemy->direction, position))
		f_sum_vetor(enemy->position, direction);
	printf("enemy x %f, enemy y %f\n", enemy->position[0], enemy->position[1]);
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

/* void	move_enemy(t_game *game)
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
 */