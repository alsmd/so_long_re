/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:41 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 16:24:20 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_poke_collition(t_game *game)
{
	t_pokemon	*poke;
	t_pokemon	*last_poke;

	poke = game->pokemons;
	last_poke = 0;
	while (poke)
	{
		if (has_player_collition(game, poke->position))
		{
			if (last_poke == 0)
				game->pokemons = poke->next;
			else
				last_poke->next = poke->next;
			free(poke);
			game->captured_poke += 1;
			return (1);
		}
		last_poke = poke;
		poke = poke->next;
	}
	return (0);
}
