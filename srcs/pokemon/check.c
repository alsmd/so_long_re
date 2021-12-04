/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:41 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 00:33:07 by flda-sil         ###   ########.fr       */
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
		if (poke->f_x == game->player.x && poke->f_y == game->player.y)
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
