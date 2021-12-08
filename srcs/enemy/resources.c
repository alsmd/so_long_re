/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:18:18 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/08 22:39:42 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	new_enemy(t_game *game, int x, int y)
{
	t_enemy	*begin;
	t_enemy	*new_enemy;
	int		move;

	new_enemy = (t_enemy *) ft_calloc(1, sizeof(t_enemy));
	f_new_vetor(new_enemy->position, x, y);
	move = my_rand() % 4;
	if (move == 0)
		f_new_vetor(new_enemy->direction, 0, 1);
	if (move == 1)
		f_new_vetor(new_enemy->direction, 0, -1);
	if (move == 2)
		f_new_vetor(new_enemy->direction, -1, 0);
	if (move == 3)
		f_new_vetor(new_enemy->direction, 1, 0);
	begin = game->enemies;
	while (begin && begin->next)
		begin = begin->next;
	if (!begin)
		game->enemies = new_enemy;
	else
		begin->next = new_enemy;
}

void	create_enemies(t_game *game)
{
	t_pokemon	*poke;
	int			x;
	int			y;

	poke = game->pokemons;
	while (poke)
	{
		x = poke->position[0];
		y = poke->position[1];
		if (game->map.array[y][x + 1] == FLOOR)
			new_enemy(game, x + 1, y);
		else if (game->map.array[y][x - 1] == FLOOR)
			new_enemy(game, x - 1, y);
		else if (game->map.array[y + 1][x] == FLOOR)
			new_enemy(game, x, y + 1);
		else if (game->map.array[y - 1][x] == FLOOR)
			new_enemy(game, x, y - 1);
		poke = poke->next;
	}
}

void	enemy_sprites(t_game *game)
{
	t_sprite	*sprite;

	sprite = &game->resources.enemy;
	load_img(&sprite->down[0], "./assets/imgs/enemy/down_0.xpm", game);
	load_img(&sprite->down[1], "./assets/imgs/enemy/down_1.xpm", game);
	load_img(&sprite->down[2], "./assets/imgs/enemy/down_2.xpm", game);
	load_img(&sprite->up[0], "./assets/imgs/enemy/up_0.xpm", game);
	load_img(&sprite->up[1], "./assets/imgs/enemy/up_1.xpm", game);
	load_img(&sprite->up[2], "./assets/imgs/enemy/up_2.xpm", game);
	load_img(&sprite->left[0], "./assets/imgs/enemy/left_0.xpm", game);
	load_img(&sprite->left[1], "./assets/imgs/enemy/left_1.xpm", game);
	load_img(&sprite->left[2], "./assets/imgs/enemy/left_2.xpm", game);
	load_img(&sprite->right[0], "./assets/imgs/enemy/right_0.xpm", game);
	load_img(&sprite->right[1], "./assets/imgs/enemy/right_1.xpm", game);
	load_img(&sprite->right[2], "./assets/imgs/enemy/right_2.xpm", game);
}

void	free_enemy_sprites(t_game *game)
{
	t_sprite	*sprite;
	t_enemy		*begin;
	t_enemy		*tmp;

	begin = game->enemies;
	sprite = &game->resources.enemy;
	mlx_destroy_image(game->vars.mlx, sprite->down[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->down[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->down[2].img);
	mlx_destroy_image(game->vars.mlx, sprite->up[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->up[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->up[2].img);
	mlx_destroy_image(game->vars.mlx, sprite->left[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->left[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->left[2].img);
	mlx_destroy_image(game->vars.mlx, sprite->right[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->right[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->right[2].img);
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}
