/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:07:35 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 20:55:10 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	player_is_on_screen(t_game *game, int x_offset , int y_offset)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y  < game->height)
	{
		while (x < game->width)
		{
			if (game->map.array[y + y_offset][x + x_offset] == PLAYER)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}

	return (0);
}

static int	set_cam(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map.height - game->height)
	{
		while (x < game->map.width - game->width)
		{
			if (player_is_on_screen(game, x, y))
			{
				game->map.desloc_x = x;
				game->map.desloc_y = y;
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}


int	game_config(t_game *game)
{
	if (game->map.width > 15)
		game->width = 15;
	else
		game->width = game->map.width;
	if (game->map.height > 15)
		game->height = 15;
	else
		game->height = game->map.height;
	game->vars.mlx = mlx_init();
	if (game->vars.mlx == 0)
		return (SERVER_ERROR);
	game->vars.win = mlx_new_window(game->vars.mlx, game->width * BLOCK_SIZE, \
			game->height * BLOCK_SIZE, "teste");
	if (game->vars.win == 0)
		return (SERVER_ERROR);
	set_cam(game);
	load_resources(game);
	game->vel = 0.1f;
	return (0);
}
