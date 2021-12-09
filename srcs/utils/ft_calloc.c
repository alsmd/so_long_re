/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:43:55 by flavio            #+#    #+#             */
/*   Updated: 2021/12/09 17:07:18 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	size_t	index;

	index = 0;
	if (nmemb * size > INT_MAX)
		return (0);
	r = malloc(nmemb * size);
	if (r)
	{
		while (index < nmemb * size)
		{
			((char *)r)[index] = 0;
			index++;
		}
		return (r);
	}
	return (0);
}
