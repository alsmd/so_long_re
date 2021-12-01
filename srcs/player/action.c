/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 00:19:30 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_move(t_game *game, int move)
{
	int	*x;
	int	*y;

	x = &game->player.x;
	y = &game->player.y;
	if (move == DOWN)
	{
		game->map.array[*y][*x] = FLOOR;
		*y += 1;
		game->map.array[*y][*x] = PLAYER;
	}
	if (move == UP)
	{
		game->map.array[*y][*x] = FLOOR;
		*y -= 1;
		game->map.array[*y][*x] = PLAYER;
	}
	if (move == LEFT)
	{
		game->map.array[*y][*x] = FLOOR;
		*x -= 1;
		game->map.array[*y][*x] = PLAYER;
	}
	if (move == RIGHT)
	{
		game->map.array[*y][*x] = FLOOR;
		*x += 1;
		game->map.array[*y][*x] = PLAYER;
	}
}
