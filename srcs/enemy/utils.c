/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:36:59 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/08 01:04:52 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	enemy_range_on_screen(t_game *game, double x, double y)
{
	if (is_on_screen(game, x, y))
		return (1);
	if (is_on_screen(game, x + game->enemy_range - 1, y))
		return (1);
	if (is_on_screen(game, x - game->enemy_range - 1, y))
		return (1);
	if (is_on_screen(game, x, y - game->enemy_range - 1))
		return (1);
	if (is_on_screen(game, x, y + game->enemy_range - 1))
		return (1);
	return (0);
}
