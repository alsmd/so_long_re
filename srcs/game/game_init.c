/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:52:01 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/03 00:16:07 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	update_frame(t_game *game)
{

	render_map(game);
	render_player(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->map.render_map.img, 0, 0);
	return (1);
}

static void	close_game(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	free(game->map.array[0]);
	exit(1);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == ESQ)
		close_game(game);
	player_move(game, keycode);
	return (1);
}


int	game_init(t_game *game)
{
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, keypress, game);
	mlx_loop_hook(game->vars.mlx, update_frame, game);
	mlx_loop(game->vars.mlx);
	return (1);
}
