/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 02:32:22 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_y(t_game *game, int move)
{
	int	*x;
	int	*y;
	int	direction;

	if (move == DOWN)
		direction = 1;
	else
		direction = -1;
	x = &game->player.x;
	y = &game->player.y;
	game->player.f_y += (0.5f * direction);
	if (game->player.f_y - game->player.y == 0.5f)
	{
		game->map.array[*y][*x] = FLOOR;
		*y += (1 * direction);	
	}
	game->map.array[*y][*x] = PLAYER;
}

static void	move_x(t_game *game, int move)
{
	int	*x;
	int	*y;
	int	direction;

	if (move == RIGHT)
		direction = 1;
	else
		direction = -1;
	x = &game->player.x;
	y = &game->player.y;
	game->player.f_x += (0.5f * direction);
	if (game->player.f_x - game->player.x == 0.5f)
	{
		game->map.array[*y][*x] = FLOOR;
		*x += (1 * direction);			
	}
	game->map.array[*y][*x] = PLAYER;
}

void	player_move(t_game *game, int move)
{
	int	i;

	i = 0;
	if ((move == DOWN || move == UP) && !check_collision_y(game, move))
		move_y(game, move);
	if ((move == RIGHT || move == LEFT) && !check_collision_x(game, move))
		move_x(game, move);
	while (i < game->map.height)
	{
		printf("%s\n", game->map.array[i]);
		i++;
	}
}
