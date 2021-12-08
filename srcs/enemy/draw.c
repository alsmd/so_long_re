/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/08 17:05:53 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	darken_pixel(t_game *game, double pos[2])
{
	int		is_on_screen;
	int		color;

	is_on_screen = pos[0] < game->width * BLOCK_SIZE && pos[0] >= 0 && \
			pos[1] >= 0 && pos[1] < game->height * BLOCK_SIZE;
	if (is_on_screen)
	{
		color = get_pixel(&game->map.render_map, pos[0], pos[1]);
		color = get_color_shade(color, 1.3);
		color = get_color_shade_red(color, 0.9);
		put_pixel(&game->map.render_map, pos[0], pos[1], color);
	}
}

int	darken_range(t_game *game, t_enemy *enemy, double pos[2])
{
	int		pixels;
	int		block;
	double	pos_cpy[2];

	block = BLOCK_SIZE - 1;
	pixels = game->enemy_range * BLOCK_SIZE;
	while (pixels > 0)
	{
		while (block > 0)
		{
			if (enemy->direction[0] != 0)
				f_new_vetor(pos_cpy, pos[0], pos[1] + block);
			else
				f_new_vetor(pos_cpy, pos[0] + block, pos[1]);
			darken_pixel(game, pos_cpy);
			block--;
		}
		block = BLOCK_SIZE - 1;
		if (enemy->direction[0] != 0)
			pos[0] += enemy->direction[0];
		else
			pos[1] += enemy->direction[1];
		pixels--;
	}
	return (0);
}

static t_data	*get_enemy_sprite(t_game *game, t_enemy *enemy)
{
	enemy->delay += 1;
	if (enemy->delay > FRAMES)
	{
		enemy->walk_frame += 1;
		if (enemy->walk_frame > 2)
			enemy->walk_frame = 0;
		enemy->delay = 0;
	}
	if (enemy->direction[0] == -1)
		return (&game->resources.enemy.left[enemy->walk_frame]);
	if (enemy->direction[0] == 1)
		return (&game->resources.enemy.right[enemy->walk_frame]);
	if (enemy->direction[1] == -1)
		return (&game->resources.enemy.up[enemy->walk_frame]);
	if (enemy->direction[1] == 1)
		return (&game->resources.enemy.down[enemy->walk_frame]);
	return (0);
}

void	render_enemy(t_game *game)
{
	t_enemy		*enemy;
	t_data		*sprite;
	double		position[2];

	enemy = game->enemies;
	while (enemy)
	{
		if (enemy_range_on_screen(game, enemy->position[0], enemy->position[1]))
		{
			f_copy_vetor(position, enemy->position);
			f_sub_vetor(position, game->map.desloc);
			f_vec_scale(position, BLOCK_SIZE);
			sprite = get_enemy_sprite(game, enemy);
			copy_img_to(&game->map.render_map, sprite, \
				to_array(position[0], position[1], BLOCK_SIZE, BLOCK_SIZE));
			if (enemy->direction[1] == 1)
				position[1] += BLOCK_SIZE;
			if (enemy->direction[0] == 1)
				position[0] += BLOCK_SIZE;
			darken_range(game, enemy, position);
		}
		enemy = enemy->next;
	}
}
