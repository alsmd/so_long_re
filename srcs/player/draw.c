/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 00:24:58 by flda-sil         ###   ########.fr       */
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

static void	draw_poke_animation(t_game *game, int x, int y)
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
		draw_poke_animation(game, x, y);
	else
	{
		copy_img_to(&game->map.render_map, &direction[frame], \
			to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	}
}
