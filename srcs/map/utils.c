/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:05:18 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/03 18:00:58 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*get_map(int fd)
{
	char	*map;
	char	*line;

	map = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	if (*map == '\0' || is_empty(map))
	{
		free(map);
		return (0);
	}
	return (map);
}

static int	get_qnt_line(char *str)
{
	int	len;
	int	index;

	index = 0;
	len = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			len++;
		index++;
	}
	if (str[index - 1] != '\n')
		len++;
	return (len);
}

static int	ft_linelen(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

void	put_map_on_array(t_game *game, char *map)
{
	int		index;
	int		y;

	index = 0;
	y = 0;
	game->map.height = get_qnt_line(map);
	game->map.array = (char **) ft_calloc(game->map.height, sizeof(char *));
	while (map[index])
	{
		if (map[index] == '\n')
		{
			map[index] = '\0';
			index++;
		}
		if (map[index] == '\0')
			break ;
		game->map.array[y] = &map[index];
		y++;
		index += ft_linelen(&map[index]);
	}
}

int	check_element(t_game *game, int y, int *check)
{
	if (is_in(game->map.array[y], COLLETIBLE))
		check[0] = 1;
	if (is_in(game->map.array[y], EXIT))
		check[1] = 1;
	if (is_in(game->map.array[y], PLAYER))
		check[2] = 1;
}
