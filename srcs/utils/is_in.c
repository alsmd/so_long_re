/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:01:15 by flavio            #+#    #+#             */
/*   Updated: 2021/12/02 22:41:09 by flda-sil         ###   ########.fr       */
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

int	round_to_top(double n)
{
	int	res;
	int	ret;
	
	res = ((int) ((double)(n * 10))) % 10;
	ret = ((int)((float) n));
	if (res)
	{
		printf("tamo aqui %d\n", (int) (n));
		return (((int) (n)) + 1);
	}
	return (n);
}

double	my_abs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
