/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 17:56:02 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_data	*get_direction(t_game *game)
{
	static int	frame;

	if (frame > game->player.delay + FRAMES)
	{
		frame = 0;
		game->player.delay;
		game->player.walk_frame = 0;
	}
	frame++;
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

void	render_player(t_game *game)
{
	int		x;
	int		y;
	int		frame;
	t_data	*direction;

	frame = game->player.walk_frame;
	direction = get_direction(game);
	x = game->player.f_x * BLOCK_SIZE;
	y = game->player.f_y * BLOCK_SIZE;
	copy_img_to(&game->map.render_map, &direction[frame], \
			to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	//game->player.walk_frame = 0;
}
