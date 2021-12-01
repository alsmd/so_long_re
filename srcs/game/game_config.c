/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:07:35 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 19:48:00 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	game_config(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, 600, 600, "teste");
	create_img(&game->map.render_map, 600, 600, game);
	load_resources(game);
	//mlx_put_image_to_window(game->vars.mlx, game->vars.win, &game->map.render_map, 0, 0);
	mlx_loop(game->vars.mlx);
}
