/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:07:35 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 20:36:42 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	load_resources(game);
	return (0);
}
