/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:33:34 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 19:37:51 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_resources(t_game *game)
{
	load_img(&game->resources.wall, "./assets/imgs/sceane/wall.xpm", game);
	load_img(&game->resources.floor, "./assets/imgs/sceane/floor.xpm", game);
}
