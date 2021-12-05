/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:41 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 20:48:12 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	has_collition(t_game *game, t_door *door)
{
	if (aprox(door->f_x, game->player.f_x + game->map.desloc_x) && \
			aprox(door->f_y, game->player.f_y + game->map.desloc_y))
		return (1);
	return (0);
}

void	check_door_collition(t_game *game)
{
	t_door	*door;

	door = game->doors;
	while (door)
	{
		if (has_collition(game, door))
		{
			game->win = 1;
			game->player.delay_animation = 0;
			game->player.walk_frame_animation = 0;
		}
		door = door->next;
	}
}
