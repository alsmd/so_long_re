/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:33:34 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 12:39:37 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_resources(t_game *game)
{
	t_resources	*resour;

	resour = &game->resources;
	player_walk_sprites(game);
	pokemon_sprites(game);
	enemy_sprites(game);
	load_img(&resour->wall, "./assets/imgs/sceane/wall.xpm", game);
	load_img(&resour->enemy_face, "./assets/imgs/enemy/enemy_face.xpm", game);
	load_img(&resour->floor[0], "./assets/imgs/sceane/floor_0.xpm", game);
	load_img(&resour->floor[1], "./assets/imgs/sceane/floor_1.xpm", game);
	load_img(&resour->floor[2], "./assets/imgs/sceane/floor_2.xpm", game);
	load_img(&resour->door[0], "./assets/imgs/sceane/door_close.xpm", \
			game);
	load_img(&resour->door[1], "./assets/imgs/sceane/door_open.xpm", \
			game);
	create_img(&game->map.render_map, game->width * BLOCK_SIZE, \
			game->height * BLOCK_SIZE, game);
	game->map.render_map.w = game->width * BLOCK_SIZE;
	game->map.render_map.h = game->height * BLOCK_SIZE;
	create_img(&game->map.full_map, game->map.width * BLOCK_SIZE, \
			game->map.height * BLOCK_SIZE, game);
	game->map.full_map.w = game->map.width * BLOCK_SIZE;
	game->map.full_map.h = game->map.height * BLOCK_SIZE;
}

static void	new_door(t_game *game, int x, int y)
{
	t_door	*begin;
	t_door	*new_door;

	new_door = (t_door *) ft_calloc(1, sizeof(t_door));
	new_door->f_x = x;
	new_door->f_y = y;
	begin = game->doors;
	while (begin && begin->next)
		begin = begin->next;
	if (!begin)
		game->doors = new_door;
	else
		begin->next = new_door;
}

void	create_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (game->map.array[y][x] == COLLETIBLE)
				new_pokemon(game, x, y);
			if (game->map.array[y][x] == EXIT)
				new_door(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	free_resources(t_game *game)
{
	t_door	*door;
	t_door	*tmp;

	door = game->doors;
	while (door)
	{
		tmp = door;
		door = door->next;
		free(tmp);
	}
	mlx_destroy_image(game->vars.mlx, game->map.render_map.img);
	mlx_destroy_image(game->vars.mlx, game->map.full_map.img);
	mlx_destroy_image(game->vars.mlx, game->resources.wall.img);
	mlx_destroy_image(game->vars.mlx, game->resources.floor[0].img);
	mlx_destroy_image(game->vars.mlx, game->resources.floor[1].img);
	mlx_destroy_image(game->vars.mlx, game->resources.floor[2].img);
	mlx_destroy_image(game->vars.mlx, game->resources.door[0].img);
	mlx_destroy_image(game->vars.mlx, game->resources.door[1].img);
	mlx_destroy_image(game->vars.mlx, game->resources.enemy_face.img);
}
