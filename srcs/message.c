/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:15:03 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 17:40:23 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_message_status(int status)
{
	char	*message;

	if (status == VALID_MAP)
		return (status);
	if (status == WRONG_MAP_EXTENTION)
		message = "Map extention must to bem \".ber\".\n";
	if (status == MAP_NOT_EXIST)
		message = "Map not found.\n";
	if (status == WRONG_MAP_FORMAT)
		message = "Map has a wrong format!\n";
	printf("%s%s%s", RED, message, WHITE);
	return (status);
}