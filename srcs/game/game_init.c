/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:52:01 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 21:42:33 by flda-sil         ###   ########.fr       */
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

int	keypress(int keycode, t_game *game)
{
	/* static double t = 4;
	int	n;

	if (keycode == RIGHT)
		t += game->vel;
	if (keycode == LEFT)
		t -= game->vel;
	n = (int) t;
	printf("numero em double: %f\n", t);
	printf("numero em decimal: %d\n", n);
	printf("casa decimal %d\n", (int) ((t * 10)) % 10); */
	player_move(game, keycode);
/* 	if (keycode == RIGHT)
		game->player.f_x += game->vel;
	if (keycode == LEFT)
		game->player.f_x -= game->vel;
	printf("float x: %f, float y: %f\n", game->player.f_x, game->player.f_y);
	printf("int x: %d, int y: %d\n", (int) game->player.f_x, (int) game->player.f_y); */
	return (1);
}


int	game_init(t_game *game)
{
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, keypress, game);
	mlx_loop_hook(game->vars.mlx, update_frame, game);
	mlx_loop(game->vars.mlx);
	return (1);
}
