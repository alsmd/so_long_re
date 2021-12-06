/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:02:41 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 21:58:04 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	has_collition_left(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	
	original_x = x;
	original_y = y;
	x += BLOCK_SIZE;
	while (x > original_x - (game->enemy_range * BLOCK_SIZE))
	{
		while (y < original_y + BLOCK_SIZE)
		{
			is_on_screen = x < game->map.width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->map.height * BLOCK_SIZE;
			if (is_on_screen)
			{
				if (aprox(x, ((game->player.f_x * BLOCK_SIZE))) && \
					aprox(y, ((game->player.f_y * BLOCK_SIZE))))
					return (1);
			}
			y++;
		}
		y = original_y;
		x--;
	}
	return (0);
}

static int	has_collition_right(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	
	original_x = x;
	original_y = y;
	while (x < original_x + (game->enemy_range * BLOCK_SIZE))
	{
		while (y < original_y + BLOCK_SIZE)
		{
			is_on_screen = x < game->map.width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->map.height * BLOCK_SIZE;
			if (is_on_screen)
			{
				if (aprox(x, ((game->player.f_x * BLOCK_SIZE))) && \
					aprox(y, ((game->player.f_y * BLOCK_SIZE))))
					return (1);
			}
			y++;
		}
		y = original_y;
		x++;
	}
	return (0);
}

static int	has_collition_up(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	
	y += BLOCK_SIZE;
	original_x = x;
	original_y = y;
	while (y > original_y - (game->enemy_range * BLOCK_SIZE))
	{
		while (x < original_x + BLOCK_SIZE)
		{
			is_on_screen = x < game->map.width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->map.height * BLOCK_SIZE;
			if (is_on_screen)
			{
				if (aprox(x, ((game->player.f_x * BLOCK_SIZE))) && \
					aprox(y, ((game->player.f_y * BLOCK_SIZE))))
					return (1);
			}
			x++;
		}
		x = original_x;
		y--;
	}
	return (0);
}

static int	has_collition_down(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	
	original_x = x;
	original_y = y;
	while (y < original_y + (game->enemy_range * BLOCK_SIZE))
	{
		while (x < original_x + BLOCK_SIZE)
		{
			is_on_screen = x < game->map.width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->map.height * BLOCK_SIZE;
			if (is_on_screen)
			{
				 
				if (aprox(x, ((game->player.f_x * BLOCK_SIZE))) && \
					aprox(y, ((game->player.f_y * BLOCK_SIZE))))
					return (1);
			}
			x++;
		}
		x = original_x;
		y++;
	}
	return (0);
}


int	check_enemy_collition(t_game *game)
{
	double	x;
	double	y;
	t_enemy	*enemy;
	int		direction;

	enemy = game->enemies;
	while (enemy && game->lost == FALSE)
	{
		direction = enemy->direction;
		x = (enemy->f_x - game->map.desloc_x) * BLOCK_SIZE;
		y = (enemy->f_y - game->map.desloc_y) * BLOCK_SIZE;
		if (direction == DOWN && has_collition_down(game, enemy, x, y))
			game->lost = 1;
		if (direction == UP && has_collition_up(game, enemy, x, y))
			game->lost = 1;
		if (direction == LEFT && has_collition_left(game, enemy, x, y))
			game->lost = 1;
		if (direction == RIGHT && has_collition_right(game, enemy, x, y))
			game->lost = 1;
		enemy = enemy->next;
	}
	return (0);
}
