/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:44:06 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 00:33:20 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	new_pokemon(t_game *game, int x, int y)
{
	t_pokemon	*begin;
	t_pokemon	*new_pokemon;

	new_pokemon = (t_pokemon *) ft_calloc(1, sizeof(t_pokemon));
	new_pokemon->id = 0;
	new_pokemon->f_x = x;
	new_pokemon->f_y = y;
	begin = game->pokemons;
	while (begin && begin->next)
		begin = begin->next;
	if (!begin)
		game->pokemons = new_pokemon;
	else
		begin->next = new_pokemon;
}

void	create_pokemons(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (game->map.array[y][x] == COLLETIBLE)
			{
				new_pokemon(game, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
