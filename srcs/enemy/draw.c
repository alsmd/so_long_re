/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 01:43:08 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_on_screen(t_game *game, double x, double y)
{
	int		visible_x;
	int		visible_y;
	double	pos;

	pos = x * BLOCK_SIZE + BLOCK_SIZE;
	visible_x = x < game->map.desloc_x + game->width;
	visible_x = (visible_x && (pos > (game->map.desloc_x * BLOCK_SIZE)));
	pos = y * BLOCK_SIZE + BLOCK_SIZE;
	visible_y = y < game->map.desloc_y + game->height;
	visible_y = (visible_y && (pos > (game->map.desloc_y * BLOCK_SIZE)));
	if (visible_x && visible_y)
		return (1);
	return (0);
}

void	render_enemy(t_game *game)
{
	t_enemy		*enemy;
	t_sprite	*sprite;
	int			x;
	int			y;

	enemy = game->enemies;
	while (enemy)
	{
		if (is_on_screen(game, enemy->f_x, enemy->f_y))
		{
			x = (enemy->f_x - game->map.desloc_x) * BLOCK_SIZE;
			y = (enemy->f_y - game->map.desloc_y) * BLOCK_SIZE;
			sprite = &game->resources.enemy;
			copy_img_to(&game->map.render_map, &sprite->down[0], \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
		}
		enemy = enemy->next;
	}
}
