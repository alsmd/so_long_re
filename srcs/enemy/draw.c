/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:08:51 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 12:08:26 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	darken_range_left(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	int		color;
	int		color_darker;
	
	x += BLOCK_SIZE;
	original_x = x;
	original_y = y;
	while (x > original_x - (game->enemy_range * BLOCK_SIZE))
	{
		while (y < original_y + BLOCK_SIZE)
		{
			is_on_screen = x < game->width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->height * BLOCK_SIZE;
			if (is_on_screen)
			{
				color = get_pixel(&game->map.render_map, x, y);
				color_darker = get_color_shade(color, 1.3);
				color_darker = get_color_shade_red(color_darker, 0.9);
				put_pixel(&game->map.render_map, x, y, color_darker);
			}
			y++;
		}
		y = original_y;
		x--;
	}
	return (0);
}

static int	darken_range_right(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	int		color;
	int		color_darker;
	
	original_x = x;
	original_y = y;
	while (x < original_x + (game->enemy_range * BLOCK_SIZE))
	{
		while (y < original_y + BLOCK_SIZE)
		{
			is_on_screen = x < game->width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->height * BLOCK_SIZE;
			if (is_on_screen)
			{
				color = get_pixel(&game->map.render_map, x, y);
				color_darker = get_color_shade(color, 1.3);
				color_darker = get_color_shade_red(color_darker, 0.9);
				put_pixel(&game->map.render_map, x, y, color_darker);
			}
			y++;
		}
		y = original_y;
		x++;
	}
	return (0);
}

static int	darken_range_up(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	int		color;
	int		color_darker;
	
	y += BLOCK_SIZE;
	original_x = x;
	original_y = y;
	while (y > original_y - (game->enemy_range * BLOCK_SIZE))
	{
		while (x < original_x + BLOCK_SIZE)
		{
			is_on_screen = x < game->width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->height * BLOCK_SIZE;
			if (is_on_screen)
			{
				color = get_pixel(&game->map.render_map, x, y);
				color_darker = get_color_shade(color, 1.3);
				color_darker = get_color_shade_red(color_darker, 0.9);
				put_pixel(&game->map.render_map, x, y, color_darker);
			}
			x++;
		}
		x = original_x;
		y--;
	}
	return (0);
}

static int	darken_range_down(t_game *game, t_enemy *enemy, double x, double y)
{
	
	double	original_x;
	double	original_y;
	int		is_on_screen;
	int		color;
	int		color_darker;
	
	original_x = x;
	original_y = y;
	while (y < original_y + (game->enemy_range * BLOCK_SIZE))
	{
		while (x < original_x + BLOCK_SIZE)
		{
			is_on_screen = x < game->width * BLOCK_SIZE && x >= 0 && \
					y >= 0 && y < game->height * BLOCK_SIZE;
			if (is_on_screen)
			{
				color = get_pixel(&game->map.render_map, x, y);
				color_darker = get_color_shade(color, 1.3);
				color_darker = get_color_shade_red(color_darker, 0.9);
				put_pixel(&game->map.render_map, x, y, color_darker);
			}
			x++;
		}
		x = original_x;
		y++;
	}
	return (0);
}

void	render_enemy(t_game *game)
{
	t_enemy		*enemy;
	t_data		*sprite;
	int			x;
	int			y;

	enemy = game->enemies;
	while (enemy)
	{
		if (enemy_range_on_screen(game, enemy->f_x, enemy->f_y))
		{
			x = (enemy->f_x - game->map.desloc_x) * BLOCK_SIZE;
			y = (enemy->f_y - game->map.desloc_y) * BLOCK_SIZE;
			if (enemy->direction == DOWN)
			{
				sprite = game->resources.enemy.down;
				darken_range_down(game, enemy, x, y);
			}
			if (enemy->direction == UP)
			{
				sprite = game->resources.enemy.up;
				darken_range_up(game, enemy, x, y);
			}
			if (enemy->direction == LEFT)
			{
				sprite = game->resources.enemy.left;
				darken_range_left(game, enemy, x, y);
			}
			if (enemy->direction == RIGHT)
			{
				sprite = game->resources.enemy.right;
				darken_range_right(game, enemy, x, y);
			}
			copy_img_to(&game->map.render_map, &sprite[0], \
				to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
		}
		enemy = enemy->next;
	}
}
