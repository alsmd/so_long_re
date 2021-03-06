/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:15:03 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 16:54:10 by flda-sil         ###   ########.fr       */
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
	if (status == SERVER_ERROR)
		message = "An error occurred in the server!\n";
	if (status == INVALID_ARG_NUMBER)
		message = "Number of arguments is invalid!\n";
	printf("%s%s%s", RED, message, WHITE);
	return (status);
}
