/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 14:08:34 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_data	*get_direction(t_game *game)
{
	static int	frame;

	frame++;
	if (frame > game->player.delay + FRAMES)
	{
		frame = 0;
		game->player.delay = 0;
		game->player.walk_frame = 0;
	}
	if (game->player.direction == DOWN)
		return (game->player.sprite.down);
	if (game->player.direction == UP)
		return (game->player.sprite.up);
	if (game->player.direction == LEFT)
		return (game->player.sprite.left);
	if (game->player.direction == RIGHT)
		return (game->player.sprite.right);
	return (0);
}

static void	draw_capturing_animation(t_game *game, int x, int y)
{
	int	frame;

	frame = game->player.walk_frame_animation;
	copy_img_to(&game->map.render_map, &game->player.getting_poke[frame], \
			to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	if (frame < 8)
	{
		if (game->player.delay_animation > FRAMES)
		{
			game->player.walk_frame_animation += 1;
			game->player.delay_animation = 0;
		}
		game->player.delay_animation += 1;
	}
	else
	{
		game->getting_poke = FALSE;
		game->player.direction = UP;
	}
}

static void	draw_victory(t_game *game, int x, int y)
{
	static int	side;
	static int	render;
	int			frame;

	frame = game->player.walk_frame_animation;
	copy_img_to(&game->map.render_map, &game->player.victory[frame], \
			to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	if (render > 3)
	{
		copy_img_to(&game->map.render_map, &game->resources.reset_message, \
			to_array((game->width / 2) * BLOCK_SIZE - 100, (game->height * BLOCK_SIZE)  - 150 , 200, 100));
	}
	if (game->player.delay_animation > FRAMES)
	{
		if (frame < 1)
		{
			if (side != 1)
			{
				game->player.walk_frame_animation = 1;
			}
			else
				game->player.walk_frame_animation = 2;
			side = game->player.walk_frame_animation;
		}
		else
			game->player.walk_frame_animation = 0;
		game->player.delay_animation = 0;
		render++;
	}
	game->player.delay_animation++;
}

static void	draw_lost(t_game *game, int x, int y)
{
	int			frame;
	static int	render;
	
	frame = game->player.walk_frame_animation;
	copy_img_to(&game->map.render_map, &game->player.lost[frame], \
			to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	copy_img_to(&game->map.render_map, &game->resources.enemy_face, \
		to_array((game->enemy_found->f_x - game->map.desloc_x) * BLOCK_SIZE, (game->enemy_found->f_y - game->map.desloc_y) * BLOCK_SIZE - 100, 150, 100));
	if (render > 3)
	{
		copy_img_to(&game->map.render_map, &game->resources.reset_message, \
			to_array((game->width / 2) * BLOCK_SIZE - 100, (game->height * BLOCK_SIZE)  - 150 , 200, 100));
	}
	if (game->player.delay_animation > FRAMES)
	{
		if (frame < 3)
			game->player.walk_frame_animation += 1;
		else
			game->player.walk_frame_animation = 0;
		game->player.delay_animation = 0;
		render++;
	}
	game->player.delay_animation++;
}

void	render_player(t_game *game)
{
	int		x;
	int		y;
	int		frame;
	t_data	*direction;

	frame = game->player.walk_frame;
	direction = get_direction(game);
	x = (game->player.f_x) * BLOCK_SIZE;
	y = (game->player.f_y) * BLOCK_SIZE;
	if (game->getting_poke == TRUE)
		draw_capturing_animation(game, x, y);
	else if (game->win == TRUE)
		draw_victory(game, x, y);
	else if (game->lost == TRUE)
		draw_lost(game, x, y);
	else
	{
		copy_img_to(&game->map.render_map, &direction[frame], \
			to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	}
}
