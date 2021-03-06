/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:31:47 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 17:04:43 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_extension(char *map_name)
{
	int	index;

	index = ft_strlen(map_name) - 1;
	if (index < 3)
		return (0);
	if (map_name[index] != 'r')
		return (0);
	if (map_name[index - 1] != 'e')
		return (0);
	if (map_name[index - 2] != 'b')
		return (0);
	if (map_name[index - 3] != '.')
		return (0);
	return (1);
}

static int	check_map_exist(char *map_name, int *fd)
{
	int	tmp_fd;

	tmp_fd = open(map_name, O_RDONLY);
	if (tmp_fd == -1)
		return (0);
	*fd = tmp_fd;
	return (1);
}

static int	check_map_elements(t_game *game)
{
	int	y;
	int	check[3];
	int	x;

	y = 0;
	x = 0;
	ft_bzero(check, sizeof(int) * 3);
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (!is_in(ELEMENTS, game->map.array[y][x]))
				return (0);
			x++;
		}
		check_element(game, y, check);
		x = 0;
		y++;
	}
	return (check[0] & check[1] & check[2]);
}

static int	check_map_format(t_game *game, int fd)
{
	int		len;
	int		y;
	char	*map;

	y = 0;
	map = get_map(fd);
	if (!map)
		return (0);
	put_map_on_array(game, map);
	game->map.width = ft_strlen(game->map.array[0]);
	if (!check_map_elements(game))
		return (0);
	while (y < game->map.height)
	{
		len = ft_strlen(game->map.array[y]);
		if (len != game->map.width)
			return (0);
		if (game->map.array[y][0] != '1' || game->map.array[y][len - 1] != '1')
			return (0);
		y++;
	}
	if (!only_has(game->map.array[0], WALL) || \
		!only_has(game->map.array[y - 1], WALL))
		return (0);
	return (1);
}

int	map_check(t_game *game, char *map_name)
{
	int	fd;

	if (!check_extension(map_name))
		return (WRONG_MAP_EXTENTION);
	if (!check_map_exist(map_name, &fd))
		return (MAP_NOT_EXIST);
	if (!check_map_format(game, fd))
	{
		free(game->map.array[0]);
		free(game->map.array);
		return (WRONG_MAP_FORMAT);
	}
	close(fd);
	return (VALID_MAP);
}
