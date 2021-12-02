/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:25:59 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 21:42:03 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_player_cord(t_game *game)
{
	int	y;
	int	x;
	int	index;

	y = 0;
	x = 0;
	index = 1;
	game->player.f_x = 0;
	game->player.f_y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (game->map.array[y][x] == PLAYER)
			{
				game->player.x = x;
				game->player.y = y;
				while (index <= x)
				{
					game->player.f_x += 1.0f;
					index++;
				}
				index = 1;
				while (index <= y)
				{
					game->player.f_y += 1.0f;
					index++;
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	player_walk_sprites(t_game *game)
{
	t_sprite	*sprite;

	sprite = &game->player.sprite;
	game->player.walk_frame = 0;
	game->player.direction = DOWN;
	game->player.delay = 0;
	load_img(&sprite->down[0], "./assets/imgs/player/down_0.xpm", game);
	load_img(&sprite->down[1], "./assets/imgs/player/down_1.xpm", game);
	load_img(&sprite->down[2], "./assets/imgs/player/down_2.xpm", game);
	load_img(&sprite->down[3], "./assets/imgs/player/down_3.xpm", game);
	load_img(&sprite->up[0], "./assets/imgs/player/up_0.xpm", game);
	load_img(&sprite->up[1], "./assets/imgs/player/up_1.xpm", game);
	load_img(&sprite->up[2], "./assets/imgs/player/up_2.xpm", game);
	load_img(&sprite->up[3], "./assets/imgs/player/up_3.xpm", game);
	load_img(&sprite->left[0], "./assets/imgs/player/left_0.xpm", game);
	load_img(&sprite->left[1], "./assets/imgs/player/left_1.xpm", game);
	load_img(&sprite->left[2], "./assets/imgs/player/left_2.xpm", game);
	load_img(&sprite->left[3], "./assets/imgs/player/left_3.xpm", game);
	load_img(&sprite->right[0], "./assets/imgs/player/right_0.xpm", game);
	load_img(&sprite->right[1], "./assets/imgs/player/right_1.xpm", game);
	load_img(&sprite->right[2], "./assets/imgs/player/right_2.xpm", game);
	load_img(&sprite->right[3], "./assets/imgs/player/right_3.xpm", game);
}
