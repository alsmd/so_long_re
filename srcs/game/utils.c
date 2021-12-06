/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:54:02 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 18:29:59 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	aprox(double a, double b)
{
	return (my_abs(a - b) < APROX_MIN);
}

int	is_on_screen(t_game *game, double x, double y)
{
	int		visible_x;
	int		visible_y;
	double	pos;

	pos = x * BLOCK_SIZE + BLOCK_SIZE;
	visible_x = x < game->map.desloc_x + game->width;
	visible_x = (visible_x && (pos > (game->map.desloc_x * BLOCK_SIZE)));
	pos = y * BLOCK_SIZE + BLOCK_SIZE;
	visible_y = y < game->map.desloc_y + game->height;
	visible_y = (visible_y && (pos > (game->map.desloc_y * BLOCK_SIZE)));
	if (visible_x && visible_y)
		return (1);
	return (0);
}
