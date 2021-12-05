/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:41 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 18:44:39 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	has_collition(t_game *game, t_pokemon *poke)
{
	if (aprox(poke->f_x, game->player.f_x + game->map.desloc_x) && \
			aprox(poke->f_y, game->player.f_y + game->map.desloc_y))
		return (1);
	return (0);
}

int	check_poke_collition(t_game *game)
{
	t_pokemon	*poke;
	t_pokemon	*last_poke;

	poke = game->pokemons;
	last_poke = 0;
	while (poke)
	{
		if (has_collition(game, poke))
		{
			if (last_poke == 0)
			{
				game->pokemons = poke->next;
				free(poke);
			}
			else
			{
				last_poke->next = poke->next;
				free(poke);
			}
			return (1);
		}
		last_poke = poke;
		poke = poke->next;
	}
	return (0);
}