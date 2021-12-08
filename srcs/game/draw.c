/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:51:20 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 20:52:04 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_door(t_game *game)
{
	t_door	*door;
	t_data	*sprite;
	double	position[2];
	int		is_open;

	if (game->pokemons == 0)
		is_open = 1;
	else
		is_open = 0;
	door = game->doors;
	while (door)
	{
		f_copy_vetor(position, door->position);
		if (is_on_screen(game, position[0], position[1]))
		{
			f_sub_vetor(position, game->map.desloc);
			f_vec_scale(position, BLOCK_SIZE);
			sprite = &game->resources.door[is_open];
			copy_img_to(&game->map.render_map, sprite, \
				to_array(position[0], position[1], BLOCK_SIZE, BLOCK_SIZE));
		}
		door = door->next;
	}
}
