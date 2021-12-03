/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/03 18:40:21 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_block(t_game *game, int x, int y)
{
	char	block;

	block = game->map.array[y][x];
	x *= BLOCK_SIZE;
	y *= BLOCK_SIZE;
	if (block == WALL)
	{
		copy_img_to(&game->map.full_map, &game->resources.wall, \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	}
	else
	{
		copy_img_to(&game->map.full_map, &game->resources.floor, \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	}
}

void	render_map(t_game *game)
{
	copy_img_from(&game->map.render_map, &game->map.full_map, \
				to_array(game->map.desloc_x * BLOCK_SIZE, \
				game->map.desloc_y * BLOCK_SIZE, \
				game->width * BLOCK_SIZE, game->height * BLOCK_SIZE));
}

void	draw_fullmap(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			draw_block(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
