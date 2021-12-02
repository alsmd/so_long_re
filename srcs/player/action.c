/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 04:14:19 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_y(t_game *game, int move)
{
	int	half_step;

	if (move == DOWN)
		game->player.f_y += .5;
	else
		game->player.f_y -= .5;
	half_step = (((int)(game->player.f_y * 10)) % 10);
	if ((half_step == 0 && move == UP))
	{
		game->map.array[game->player.y][game->player.x] = FLOOR;
		game->player.y -= 1;
	}
	if ((half_step == 5 && move == DOWN))
	{
		game->map.array[game->player.y][game->player.x] = FLOOR;
		game->player.y += 1;
	}
}

static void	move_x(t_game *game, int move)
{
	int	half_step;

	if (move == RIGHT)
		game->player.f_x += .5;
	else
		game->player.f_x -= .5;
	half_step = (((int)(game->player.f_x * 10)) % 10);
	if ((half_step == 0 && move == LEFT))
	{
		game->map.array[game->player.y][game->player.x] = FLOOR;
		game->player.x -= 1;
	}
	if ((half_step == 5 && move == RIGHT))
	{
		game->map.array[game->player.y][game->player.x] = FLOOR;
		game->player.x += 1;
	}
}

void	player_move(t_game *game, int move)
{
	int	half_step;
	
	if ((move == LEFT || move == RIGHT) && !check_collision_x(game, move))
		move_x(game, move); 
	if ((move == DOWN || move == UP) && !check_collision_y(game, move))
		move_y(game, move);
	game->map.array[game->player.y][game->player.x] = PLAYER;
	int i;

	i = 0;
	while (i < game->map.height)
	{
		printf("%s\n", game->map.array[i]);
		i++;
	}
}