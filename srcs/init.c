/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:11:31 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 16:55:26 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init(char *map, t_game *game)
{
	int		status;

	ft_bzero(game, sizeof(t_game));
	status = map_check(game, map);
	if (status != VALID_MAP)
		return (print_message_status(status));
	status = game_config(game);
	if (status == SERVER_ERROR)
	{
		free(game->map.array[0]);
		free(game->map.array);
		return (print_message_status(status));
	}
	game_init(game);
	return (GAME_FINISHED);
}
