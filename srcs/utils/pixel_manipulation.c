/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:47 by flavio            #+#    #+#             */
/*   Updated: 2021/12/09 15:55:49 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;
	int		bytes;

	bytes = (data->bits_per_pixel / 8);
	dest = data->addr + (y * data->line_length + x * bytes);
	if ((x >= 0 && x <= data->w) && (y >= 0 && y <= data->h))
		*(unsigned int *)dest = color;
}

int	get_pixel(t_data *data, int x, int y)
{
	char	*dest;
	int		bytes;

	bytes = (data->bits_per_pixel / 8);
	dest = data->addr + (y * data->line_length + x * bytes);
	return (*(unsigned int *)dest);
}

void	copy_img_from(t_data *dest, t_data *src, int info[4])
{
	int	pixel;
	int	x;
	int	y;
	int	holder;

	x = 0;
	y = 0;
	holder = info[1];
	while (x < info[2])
	{
		while (y < info[3])
		{
			pixel = get_pixel(src, info[0], info[1]);
			if (pixel != TRANSPARENT)
				put_pixel(dest, x, y, pixel);
			y++;
			info[1]++;
		}
		y = 0;
		info[1] = holder;
		info[0]++;
		x++;
	}
	free(info);
}

void	copy_img_to(t_data *dest, t_data *src, int info[4])
{
	int	pixel;
	int	x;
	int	y;
	int	holder;

	x = 0;
	y = 0;
	holder = info[1];
	while (x < info[2])
	{
		while (y < info[3])
		{
			pixel = get_pixel(src, x, y);
			if (pixel != TRANSPARENT)
				put_pixel(dest, info[0], info[1], \
					get_color_shade(pixel, DARKNESS));
			y++;
			info[1]++;
		}
		y = 0;
		info[1] = holder;
		info[0]++;
		x++;
	}
	free(info);
}

int	*to_array(int x, int y, int w, int h)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * 4);
	array[0] = x;
	array[1] = y;
	array[2] = w;
	array[3] = h;
	return (array);
}
