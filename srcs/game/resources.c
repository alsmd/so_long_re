/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:33:34 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/04 15:19:10 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_resources(t_game *game)
{
	player_walk_sprites(game);
	pokemon_sprites(game);
	load_img(&game->resources.wall, "./assets/imgs/sceane/wall.xpm", game);
	load_img(&game->resources.floor, "./assets/imgs/sceane/floor.xpm", game);
	create_img(&game->map.render_map, game->width * BLOCK_SIZE, \
			game->height * BLOCK_SIZE, game);
	game->map.render_map.w = game->width * BLOCK_SIZE;
	game->map.render_map.h = game->height * BLOCK_SIZE;
	create_img(&game->map.full_map, game->map.width * BLOCK_SIZE, \
			game->map.height * BLOCK_SIZE, game);
	game->map.full_map.w = game->map.width * BLOCK_SIZE;
	game->map.full_map.h = game->map.height * BLOCK_SIZE;
}
