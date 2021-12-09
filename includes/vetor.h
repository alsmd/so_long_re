/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vetor.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:16:24 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 15:45:55 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VETOR_H
# define VETOR_H

/*
	@brief	Inicialize a new vetor vetor[0] = x vetor[1] = y
*/
void	new_vetor(int vetor[2], int x, int y);

/*
	@brief	Vetor operations, result is stored inside the first vetor
*/
void	sum_vetor(int v1[2], int v2[2]);
void	multi_vetor(int v1[2], int v2[2]);
void	copy_vetor(int v1[2], int v2[2]);
void	sub_vetor(int v1[2], int v2[2]);
void	vec_scale(int v1[2], int scale);

/*
	@brief	Float versions
*/
void	f_new_vetor(double vetor[2], double x, double y);
void	f_sum_vetor(double v1[2], double v2[2]);
void	f_multi_vetor(double v1[2], double v2[2]);
void	f_copy_vetor(double v1[2], double v2[2]);
void	f_sub_vetor(double v1[2], double v2[2]);
void	f_vec_scale(double v1[2], double scale);
int		f_equal_vetor(double v1[2], double v2[2]);

#endif