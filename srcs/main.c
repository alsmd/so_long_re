/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:58 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 16:44:03 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		status;

	game.restart = 1;
	while (game.restart == 1)
	{
		status = init(argv[1], &game);
		if (status != VALID_MAP || status == SERVER_ERROR)
			return (status);
		mlx_destroy_display(game.vars.mlx);
		free(game.vars.mlx);
	}
	return (status);
}
