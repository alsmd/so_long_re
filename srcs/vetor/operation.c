/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:08:56 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/07 20:33:47 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sum_vetor(int v1[2], int v2[2])
{
	v1[0] += v2[0];
	v1[1] += v2[1];
}

void	multi_vetor(int v1[2], int v2[2])
{
	v1[0] *= v2[0];
	v1[1] *= v2[1];
}

void	copy_vetor(int v1[2], int v2[2])
{
	v1[0] = v2[0];
	v1[1] = v2[1];
}

void	sub_vetor(int v1[2], int v2[2])
{
	v1[0] -= v2[0];
	v1[1] -= v2[1];
}

void	vec_scale(int v1[2], int scale)
{
	v1[0] *= scale;
	v1[1] *= scale;
}