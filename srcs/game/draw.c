/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:51:20 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 18:31:59 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_door(t_game *game)
{
	t_door	*door;
	t_data	*sprite;
	int		x;
	int		y;
	int		is_open;

	if (game->pokemons == 0)
		is_open = 1;
	else
		is_open = 0;
	door = game->doors;
	while (door)
	{
		if (is_on_screen(game, door->f_x, door->f_y))
		{
			x = (door->f_x - game->map.desloc_x) * BLOCK_SIZE;
			y = (door->f_y - game->map.desloc_y) * BLOCK_SIZE;
			sprite = &game->resources.door[is_open];
			copy_img_to(&game->map.render_map, sprite, \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
		}
		door = door->next;
	}
}
