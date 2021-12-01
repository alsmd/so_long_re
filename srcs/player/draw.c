/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 00:31:05 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_player(t_game *game, int x, int y)
{
	char	block;
	int		half_step;

	half_step = BLOCK_SIZE / 2;
	block = game->map.array[y + game->map.desloc_y][x + game->map.desloc_x];
	x *= BLOCK_SIZE;
	y *= BLOCK_SIZE;
	if (game->player.half_step_x)
		x += half_step;
	if (game->player.half_step_x)
		y += half_step;
	if (block == PLAYER)
	{
		copy_img_to(&game->map.render_map, &game->player.sprite.down[0], \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	}
}

void	render_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height)
	{
		while (x < game->width)
		{
			draw_player(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
