/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:52:01 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 21:23:46 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	keypress(int keycode, t_game *game)
{
	printf("do something\n");
	return (1);
}

int	update_frame(t_game *game)
{
	render_map(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
			game->map.render_map.img, 0, 0);
	return (1);
}

int	game_init(t_game *game)
{
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, keypress, game);
	mlx_loop_hook(game->vars.mlx, update_frame, game);
	mlx_loop(game->vars.mlx);
	return (1);
}
