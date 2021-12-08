/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:41 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/08 22:58:58 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	player_collition_on_range(t_game *game, double position[2])
{
	double	player_pos[2];

	f_copy_vetor(player_pos, game->player.position);
	f_vec_scale(player_pos, BLOCK_SIZE);
	if (f_equal_vetor(position, player_pos))
		return (1);
	player_pos[0] += BLOCK_SIZE - 1;
	if (f_equal_vetor(position, player_pos))
		return (1);
	player_pos[1] += BLOCK_SIZE - 1;
	if (f_equal_vetor(position, player_pos))
		return (1);
	player_pos[0] -= BLOCK_SIZE - 1;
	if (f_equal_vetor(position, player_pos))
		return (1);
	return (0);
}

static int	check_pixel(t_game *game, double pos[2])
{
	int		is_on_screen;
	int		x;
	int		y;

	x = (pos[0] / BLOCK_SIZE) + game->map.desloc[0];
	y = (pos[1] / BLOCK_SIZE) + game->map.desloc[1];
	if (game->map.array[y][x] == WALL)
		return (1);
	is_on_screen = ((pos[0] < game->width * BLOCK_SIZE && pos[0] >= 0) && \
			(pos[1] >= 0 && pos[1] < game->height * BLOCK_SIZE));
	if (is_on_screen && player_collition_on_range(game, pos))
		game->lost = TRUE;
	return (0);
}

int	check_range(t_game *game, t_enemy *enemy, double pos[2])
{
	int		pixels;
	int		block;
	double	pos_cpy[2];

	block = BLOCK_SIZE - 1;
	pixels = game->enemy_range * BLOCK_SIZE + 1;
	while (pixels++ > 0)
	{
		while (block > 0)
		{
			if (enemy->direction[0] != 0)
				f_new_vetor(pos_cpy, pos[0], pos[1] + block);
			else
				f_new_vetor(pos_cpy, pos[0] + block, pos[1]);
			if (check_pixel(game, pos_cpy))
				return (0);
			block--;
		}
		block = BLOCK_SIZE - 1;
		if (enemy->direction[0] != 0)
			pos[0] += enemy->direction[0];
		else
			pos[1] += enemy->direction[1];
	}
	return (0);
}

int	check_enemy_collition(t_game *game)
{
	double	position[2];
	t_enemy	*enemy;

	enemy = game->enemies;
	while (enemy && game->lost == FALSE)
	{
		f_copy_vetor(position, enemy->position);
		f_sub_vetor(position, game->map.desloc);
		f_vec_scale(position, BLOCK_SIZE);
		if (enemy->direction[1] == 1)
			position[1] += BLOCK_SIZE - 1;
		if (enemy->direction[0] == 1)
			position[0] += BLOCK_SIZE - 1;
		check_range(game, enemy, position);
		if (game->lost == TRUE)
		{
			game->enemy_found = enemy;
			game->player.delay_animation = 0;
			game->player.walk_frame_animation = 0;
		}
		enemy = enemy->next;
	}
	return (0);
}
