/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 03:15:56 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player.f_x * BLOCK_SIZE;
	y = game->player.f_y * BLOCK_SIZE;
		copy_img_to(&game->map.render_map, &game->player.sprite.down[0], \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
}
