/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 16:00:12 by flda-sil         ###   ########.fr       */
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
		game->player.move = DOWN;
	if (move == UP)
		game->player.move = UP;
	if (move == LEFT)
		game->player.move = LEFT;
	if (move == RIGHT)
		game->player.move = RIGHT;
}

void	player_move(t_game *game, int move)
{
	double	position[2];
	double	direction[2];

	f_copy_vetor(position, game->player.position);
	f_sum_vetor(position, game->map.desloc);
	if (move == DOWN)
		f_new_vetor(direction, 0, 1);
	if (move == UP)
		f_new_vetor(direction, 0, -1);
	if (move == LEFT)
		f_new_vetor(direction, -1, 0);
	if (move == RIGHT)
		f_new_vetor(direction, 1, 0);
	f_copy_vetor(game->player.direc, direction);
	f_multi_vetor(direction, game->player.speed);
	f_sum_vetor(position, direction);
	if (!check_collision(game, game->player.direc, position))
	{
		if (can_move_cam(game))
			f_sum_vetor(game->map.desloc, direction);
		else
			f_sum_vetor(game->player.position, direction);
		check_enemy_collition(game);
	}
}
