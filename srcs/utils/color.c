/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 02:25:13 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 16:07:13 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_color_shade(int color, double qnt_shade)
{
	int	r;
	int	g;
	int	b;

	r = ((color & (0xFF << 16)) >> 16) * qnt_shade;
	g = ((color & (0xFF << 8)) >> 8) * qnt_shade;
	b = (color & 0xFF) * qnt_shade;
	return (create_rgb(r, g, b));
}

int	get_color_shade_red(int color, double qnt_shade)
{
	int	r;
	int	g;
	int	b;

	r = ((color & (0xFF << 16)) >> 16);
	g = ((color & (0xFF << 8)) >> 8) * qnt_shade;
	b = (color & 0xFF) * qnt_shade;
	return (create_rgb(r, g, b));
}
