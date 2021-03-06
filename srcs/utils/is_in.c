/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:01:15 by flavio            #+#    #+#             */
/*   Updated: 2021/12/09 17:08:08 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_in(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	is_empty(char *str)
{
	while (*str)
	{
		if (*str != '\n')
			return (0);
		str++;
	}
	return (1);
}

double	my_abs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
