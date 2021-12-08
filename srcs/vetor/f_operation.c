/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:08:56 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 20:33:24 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	f_sum_vetor(double v1[2], double v2[2])
{
	v1[0] += v2[0];
	v1[1] += v2[1];
}

void	f_sub_vetor(double v1[2], double v2[2])
{
	v1[0] -= v2[0];
	v1[1] -= v2[1];
}

void	f_multi_vetor(double v1[2], double v2[2])
{
	v1[0] *= v2[0];
	v1[1] *= v2[1];
}

void	f_copy_vetor(double v1[2], double v2[2])
{
	v1[0] = v2[0];
	v1[1] = v2[1];
}

void	f_vec_scale(double v1[2], double scale)
{
	v1[0] *= scale;
	v1[1] *= scale;
}