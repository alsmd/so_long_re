/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:58 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 21:21:38 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	int		status;
	t_game	game;

	status = map_check(&game, "./maps/simple.ber");
	if (status != VALID_MAP)
		return (print_message_status(status));
	status = game_config(&game);
	if (status == SERVER_ERROR)
		return (print_message_status(status));
	game_init(&game);
	return (0);
}
