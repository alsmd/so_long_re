/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/04 22:58:21 by flda-sil         ###   ########.fr       */
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
	int			x;
	int			y;

	poke = game->pokemons;
	while (poke)
	{
		if (is_on_screen(game, poke->f_x, poke->f_y))
		{
			x = (poke->f_x - game->map.desloc_x) * BLOCK_SIZE;
			y = (poke->f_y - game->map.desloc_y) * BLOCK_SIZE;
			sprite = &game->resources.pokemon_sprites[poke->id];
			copy_img_to(&game->map.render_map, &sprite->down[poke->walk_frame], \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
			change_walk_frame(poke);
		}
		poke = poke->next;
	}
}
