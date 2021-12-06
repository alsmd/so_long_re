/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:58 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 02:21:36 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color_shade(int color, double qnt_shade)
{
	int	r;
	int	g;
	int	b;

	r = ((color & (0xFF << 16)) >> 16) * qnt_shade;
	g = ((color & (0xFF << 8)) >> 8) * qnt_shade;
	b = (color & 0xFF) * qnt_shade;
	return (create_trgb(0, r, g, b));
}

int	main(int argc, char *argv[])
{
	int		status;
	int		x;
	int		color;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	status = map_check(&game, "./maps/simple.ber");
	if (status != VALID_MAP)
		return (print_message_status(status));
	status = game_config(&game);
	if (status == SERVER_ERROR)
	{
		free(game.map.array[0]);
		free(game.map.array);
		return (print_message_status(status));
	}
	//game_init(&game);
	x = 0;
	color = create_trgb(0, 55, 255, 255);
	while (x < 200)
	{
		mlx_pixel_put(game.vars.mlx, game.vars.win, x, 10, color);
		x++;
	}
	x = 0;
	while (x < 200)
	{
		mlx_pixel_put(game.vars.mlx, game.vars.win, x, 50, create_trgb(0, 55 * 0.4, 255 * 0.4, 255 * 0.4));
		x++;
	}
	x = 0;
	while (x < 200)
	{
		mlx_pixel_put(game.vars.mlx, game.vars.win, x, 100, get_color_shade(color, 0.6));
		x++;
	}
	mlx_loop(game.vars.mlx);
	return (0);
}
