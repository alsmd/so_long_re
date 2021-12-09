/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:54:02 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 15:46:56 by flda-sil         ###   ########.fr       */
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
	visible_x = x < game->map.desloc[0] + game->width;
	visible_x = (visible_x && (pos > (game->map.desloc[0] * BLOCK_SIZE)));
	pos = y * BLOCK_SIZE + BLOCK_SIZE;
	visible_y = y < game->map.desloc[1] + game->height;
	visible_y = (visible_y && (pos > (game->map.desloc[1] * BLOCK_SIZE)));
	if (visible_x && visible_y)
		return (1);
	return (0);
}

int	round_up(double n)
{
	int	tmp;

	tmp = (int)(n + 0.0001f);
	if (aprox(tmp, n))
	{
		return (tmp);
	}
	return (tmp + 1);
}

int	round_down(double n)
{
	int	tmp;

	tmp = (int)(n + 0.0001f);
	if (aprox(tmp, n))
	{
		return (tmp);
	}
	return (n);
}

int	has_player_collition(t_game *game, double pos[2])
{
	double	poke_position[2];

	f_copy_vetor(poke_position, pos);
	f_sub_vetor(poke_position, game->map.desloc);
	if (f_equal_vetor(poke_position, game->player.position))
		return (1);
	return (0);
}
