/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:31:10 by flavio            #+#    #+#             */
/*   Updated: 2021/12/01 20:42:39 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_img(t_data *img, char *path, t_game *game)
{
	int	z;

	img->img = mlx_xpm_file_to_image(game->vars.mlx, path, &z, &z);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	create_img(t_data *img, int w, int h, t_game *game)
{
	img->img = mlx_new_image(game->vars.mlx, w, h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
