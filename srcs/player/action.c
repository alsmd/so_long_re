/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:54:43 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/02 23:01:55 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	change_frame(t_game *game, int move)
{
	game->player.delay += 1;
	if (game->player.walk_frame < 3)
		game->player.walk_frame += 1;
	else
		game->player.walk_frame = 1;
	if (move == DOWN)
		game->player.direction = DOWN;
	if (move == UP)
		game->player.direction = UP;
	if (move == LEFT)
		game->player.direction = LEFT;
	if (move == RIGHT)
		game->player.direction = RIGHT;
}

static void	move_y(t_game *game, int move)
{
	double	aprox;

	if (move == DOWN)
	{
		game->player.f_y += game->vel;
		aprox = game->player.y + 1;
		if (my_abs(aprox - game->player.f_y) < APROX_MIN)
		{
			game->map.array[game->player.y][game->player.x] = FLOOR;
			game->player.y += 1;
		}
	}
	else
	{
		game->player.f_y -= game->vel;
		aprox = game->player.y - 1;
		if (my_abs(aprox - game->player.f_y) < APROX_MIN)
		{
			game->map.array[game->player.y][game->player.x] = FLOOR;
			game->player.y -= 1;
		}
	}
	change_frame(game, move);
}


static void	move_x(t_game *game, int move)
{
	int		fx_in_int;
	double	aprox;
	
	if (move == RIGHT)
	{
		game->player.f_x += game->vel;
		fx_in_int = (int) ((float) game->player.f_x);
		aprox = game->player.x + 1;
		if (my_abs(aprox - game->player.f_x) < APROX_MIN)
		{
			game->map.array[game->player.y][game->player.x] = FLOOR;
			game->player.x += 1;
		}
	}
	else
	{
		game->player.f_x -= game->vel;//1.9
		fx_in_int = (int) ((float) game->player.f_x);
		aprox = game->player.x - 1;//1
		if (my_abs(game->player.f_x - aprox) < APROX_MIN)
		{
			game->map.array[game->player.y][game->player.x] = FLOOR;
			game->player.x -= 1;
		}
	}
	change_frame(game, move);

}

void	player_move(t_game *game, int move)
{
	int	half_step;
	int	index;

	index = 0;
	if ((move == LEFT || move == RIGHT) && !check_collision_x(game, move))
		move_x(game, move);
	if ((move == DOWN || move == UP) && !check_collision_y(game, move))
		move_y(game, move);

	
	game->map.array[game->player.y][game->player.x] = PLAYER;
	int i;
	printf("float x: %Lf, float y: %Lf\n", game->player.f_x, game->player.f_y);
	printf("int x: %d, int y: %d\n", (int) game->player.x, (int) game->player.y);
	printf("casa decimal %d\n", (int) ((game->player.f_x * 10)) % 10);
	printf("f_x in int: %d\n", (int) ((float) game->player.f_x));
	while (index < game->map.height)
	{
		printf("%s\n", game->map.array[index]);
		index++;
	}
}
