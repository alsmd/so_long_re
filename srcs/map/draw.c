/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 20:07:22 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_block(t_game *game, int x, int y)
{
	char		block;
	t_data		*img;
	static int	number;

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
		if (number % 21 == 0)
			img = &game->resources.floor[1];
		else if (number % 43 == 0)
			img = &game->resources.floor[2];
		else
			img = &game->resources.floor[0];
		copy_img_to(&game->map.full_map, img, \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	}
	number++;
}

void	render_map(t_game *game)
{
	copy_img_from(&game->map.render_map, &game->map.full_map, \
				to_array(game->map.desloc[0] * BLOCK_SIZE, \
				game->map.desloc[1] * BLOCK_SIZE, \
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
