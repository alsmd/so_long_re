/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:41 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 20:57:48 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_door_collition(t_game *game)
{
	t_door	*door;

	door = game->doors;
	while (door)
	{
		if (has_player_collition(game, door->position))
		{
			game->win = 1;
			game->player.delay_animation = 0;
			game->player.walk_frame_animation = 0;
			break ;
		}
		door = door->next;
	}
}
