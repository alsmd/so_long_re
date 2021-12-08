/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 21:12:33 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	change_walk_frame(t_pokemon *poke)
{
	poke->delay += 1;
	if (poke->delay >= FRAMES)
	{
		if (poke->walk_frame > 0)
			poke->walk_frame = 0;
		else
			poke->walk_frame = 1;
		poke->delay = 0;
	}
}

void	render_pokemon(t_game *game)
{
	t_pokemon	*poke;
	t_sprite	*sprite;
	double		position[2];

	poke = game->pokemons;
	while (poke)
	{
		if (is_on_screen(game, poke->position[0], poke->position[1]))
		{
			f_copy_vetor(position, poke->position);
			f_sub_vetor(position, game->map.desloc);
			f_vec_scale(position, BLOCK_SIZE);
			sprite = &game->resources.pokemon_sprites[poke->id];
			copy_img_to(&game->map.render_map, &sprite->down[poke->walk_frame], \
				to_array(position[0], position[1], BLOCK_SIZE, BLOCK_SIZE));
			change_walk_frame(poke);
		}
		poke = poke->next;
	}
}
