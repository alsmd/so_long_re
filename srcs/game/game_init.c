/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:52:01 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 00:33:52 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	update_frame(t_game *game)
{
	render_map(game);
	render_pokemon(game);
	render_player(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->map.render_map.img, 0, 0);
	return (1);
}

static void	close_game(t_game *game)
{
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_loop_end(game->vars.mlx);
	free(game->map.array[0]);
	free(game->map.array);
	free_player_walk_sprites(game);
	free_pokemon_sprites(game);
	mlx_destroy_image(game->vars.mlx, game->map.render_map.img);
	mlx_destroy_image(game->vars.mlx, game->map.full_map.img);
	mlx_destroy_image(game->vars.mlx, game->resources.wall.img);
	mlx_destroy_image(game->vars.mlx, game->resources.floor.img);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(0);
}

int	keypress(int kc, t_game *game)
{
	if (kc == ESQ)
		close_game(game);
	if (game->getting_poke == FALSE)
	{
		if (kc == DOWN || kc == UP || kc == LEFT || kc == RIGHT)
			change_frame(game, kc);
		player_move(game, kc);
		if (check_poke_collition(game))
		{
			game->getting_poke = 1;
			game->player.walk_frame_animation = 0;
			game->player.delay_animation = 0;
		}
	}
	return (1);
}

int	game_init(t_game *game)
{
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, keypress, game);
	mlx_loop_hook(game->vars.mlx, update_frame, game);
	mlx_loop(game->vars.mlx);
	return (1);
}
