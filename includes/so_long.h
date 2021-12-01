/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:22:13 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 20:31:14 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TRANSPARENT 0x010101
# define BLOCK_SIZE 32
# define WALL '1'
# define COLLETIBLE 'C'
# define FLOOR '0'
# define EXIT 'E'
# define PLAYER 'P'
# define ELEMENTS "01CEP"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
# include "get_next_line.h"
# include "utils.h"
# include <mlx.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//MAP
/*
	@brief	Will make the checks corresponding to the map and
			keep the map in an array
*/
int		map_check_controller(t_game *game, char *map_name);

/*
	@brief	Returns a string containing the map
*/

char	*get_map(int fd);

/*
	@brief put the map in the array game->map.array where each line is the
			first array's dimention and each colomn is the second
*/
void	put_map_on_array(t_game *game, char *map);

/*
	@brief	draw the current map on game.map.render_map
*/
void	render_map(t_game *game);

//GAME
/*
	@brief	Prints the message correspondent to the status.
			returns status.
*/
int		print_message_status(int status);

/*
	@brief set game configurations
*/
int		game_config(t_game *game);


//RESOURCES
/*
	@brief	Load the game resources.
*/
void	load_resources(t_game *game);


//PLAYER

/*
	@brief	load player's walk sprites
*/
void	player_walk_sprites(t_game *game);

#endif