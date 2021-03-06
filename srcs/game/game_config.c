/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:07:35 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 18:21:58 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	player_is_on_screen(t_game *game, int x_offset, int y_offset)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height)
	{
		while (x < game->width)
		{
			if (game->map.array[y + y_offset][x + x_offset] == PLAYER)
			{
				return (1);
			}
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
	while (y <= game->map.height - game->height)
	{
		while (x <= game->map.width - game->width)
		{
			if (player_is_on_screen(game, x, y))
			{
				game->map.desloc_x = x;
				game->map.desloc_y = y;
				f_new_vetor(game->map.desloc, x, y);
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

static void	set_game_size(t_game *game)
{
	if (game->map.width > 25)
		game->width = 25;
	else
		game->width = game->map.width;
	if (game->map.height > 18)
		game->height = 18;
	else
		game->height = game->map.height;
}

int	game_config(t_game *game)
{
	set_game_size(game);
	game->vars.mlx = mlx_init();
	if (game->vars.mlx == 0)
		return (SERVER_ERROR);
	game->vars.win = mlx_new_window(game->vars.mlx, game->width * BLOCK_SIZE, \
			game->height * BLOCK_SIZE, "So_Long");
	if (game->vars.win == 0)
		return (SERVER_ERROR);
	set_cam(game);
	load_resources(game);
	set_player_cord(game);
	create_elements(game);
	create_enemies(game);
	draw_fullmap(game);
	f_new_vetor(game->player.speed, 0.25f, 0.25f);
	f_new_vetor(game->enemy_speed, 0.01f, 0.01f);
	game->enemy_range = 2;
	return (0);
}
