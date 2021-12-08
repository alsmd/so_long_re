/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:25:59 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 20:17:50 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_player_cord(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (game->map.array[y][x] == PLAYER)
			{
				game->player.x = x;
				game->player.y = y;
				game->player.f_x = x - game->map.desloc_x;
				game->player.f_y = y - game->map.desloc_y;
				game->player.position[0] = x - game->map.desloc[0];
				game->player.position[1] = y - game->map.desloc[1];
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static void	free_animations(t_game *game)
{
	int		index;

	index = 0;
	while (index < 9)
	{
		mlx_destroy_image(game->vars.mlx, game->player.getting_poke[index].img);
		index++;
	}
	mlx_destroy_image(game->vars.mlx, game->player.victory[0].img);
	mlx_destroy_image(game->vars.mlx, game->player.victory[1].img);
	mlx_destroy_image(game->vars.mlx, game->player.victory[2].img);
	mlx_destroy_image(game->vars.mlx, game->player.lost[0].img);
	mlx_destroy_image(game->vars.mlx, game->player.lost[1].img);
	mlx_destroy_image(game->vars.mlx, game->player.lost[2].img);
	mlx_destroy_image(game->vars.mlx, game->player.lost[3].img);
}

static void	animations(t_game *game)
{
	t_data	*frame;
	char	*src;
	char	*name;
	char	*full_src;
	int		index;

	index = 0;
	while (index < 9)
	{
		src = ft_strdup("./assets/animation/capturing_poke/");
		name = ft_strjoin(ft_itoa(index), ft_strdup(".xpm"));
		frame = &game->player.getting_poke[index];
		full_src = ft_strjoin(src, name);
		load_img(frame, full_src, game);
		free(full_src);
		index++;
	}
	frame = game->player.victory;
	load_img(&frame[0], "./assets/animation/victory/0.xpm", game);
	load_img(&frame[1], "./assets/animation/victory/1.xpm", game);
	load_img(&frame[2], "./assets/animation/victory/2.xpm", game);
	frame = game->player.lost;
	load_img(&frame[0], "./assets/animation/lost/0.xpm", game);
	load_img(&frame[1], "./assets/animation/lost/1.xpm", game);
	load_img(&frame[2], "./assets/animation/lost/2.xpm", game);
	load_img(&frame[3], "./assets/animation/lost/3.xpm", game);
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
	animations(game);
}

void	free_player_walk_sprites(t_game *game)
{
	t_sprite	*sprite;

	sprite = &game->player.sprite;
	mlx_destroy_image(game->vars.mlx, sprite->down[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->down[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->down[2].img);
	mlx_destroy_image(game->vars.mlx, sprite->down[3].img);
	mlx_destroy_image(game->vars.mlx, sprite->up[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->up[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->up[2].img);
	mlx_destroy_image(game->vars.mlx, sprite->up[3].img);
	mlx_destroy_image(game->vars.mlx, sprite->left[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->left[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->left[2].img);
	mlx_destroy_image(game->vars.mlx, sprite->left[3].img);
	mlx_destroy_image(game->vars.mlx, sprite->right[0].img);
	mlx_destroy_image(game->vars.mlx, sprite->right[1].img);
	mlx_destroy_image(game->vars.mlx, sprite->right[2].img);
	mlx_destroy_image(game->vars.mlx, sprite->right[3].img);
	free_animations(game);
}
