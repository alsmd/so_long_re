/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:49:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/08 00:31:13 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_collision(t_game *game, double direction[2], double position[2])
{
	int	i_position[2];
	int	i_position_2[2];

	if (direction[0] > 0)
		i_position[0] = round_up(position[0]);
	else
		i_position[0] = round_down(position[0]);
	if (direction[1] > 0)
		i_position[1] = round_up(position[1]);
	else
		i_position[1] = round_down(position[1]);
	if (direction[0] != 0)
	{
		i_position_2[0] = i_position[0];
		i_position_2[1] = round_up(position[1]);
	}
	if (direction[1] != 0)
	{
		i_position_2[0] = round_up(position[0]);
		i_position_2[1] = i_position[1];;
	}
	if (game->map.array[i_position[1]][i_position[0]] == WALL)
		return (1);
	if (game->map.array[i_position_2[1]][i_position_2[0]] == WALL)
		return (1);
	return (0);
}

int	can_move_cam(t_game *game)
{
	double	pos[2];
	double	direction[2];
	double	desloc[2];
	double	width;
	double	heig;

	width = game->map.width;
	heig = game->map.height;
	f_copy_vetor(pos, game->player.position);
	f_copy_vetor(direction, game->player.direc);
	f_copy_vetor(desloc, game->map.desloc);
	if (direction[0] != 0)
	{
		if (pos[0] >= game->width / 2 && direction[0] > 0 && desloc[0] + game->width < width)
			return (1);
		else if (pos[0] <= game->width / 2 && direction[0] < 0 && desloc[0] > 0)
			return (1);
	}
	if (direction[1] != 0)
	{
		if (pos[1] >= game->height / 2 && direction[1] > 0 && desloc[1] + game->height < heig)
			return (1);
		else if (pos[1] < game->height / 2 && direction[1] < 0 && desloc[1] > 0)
			return (1);
	}
	return (0);
}
