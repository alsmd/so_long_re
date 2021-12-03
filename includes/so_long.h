/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:22:13 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/03 22:19:57 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define FRAMES 60
# define TRANSPARENT 0x589058
# define BLOCK_SIZE 32
# define WALL '1'
# define COLLETIBLE 'C'
# define FLOOR '0'
# define EXIT 'E'
# define PLAYER 'P'
# define ELEMENTS "01CEP"
# define RED "\033[0;31m"
# define WHITE "\033[0;37m"
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESQ 65307
# define APROX_MAX 0.9
# define APROX_MIN 0.0001
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
int		map_check(t_game *game, char *map_name);

/*
	@brief	map_check's helper
*/
int		check_element(t_game *game, int y, int *check);

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

/*
	@brief	draw the full map on game.map.full_map
*/
void	draw_fullmap(t_game *game);

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

/*
	@brief	Init our game.
*/
int		game_init(t_game *game);

/*
	@brief Checks if a and b have an aproximated value
*/
int		aprox(double a, double b);

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

/*
	@brief	frees player's walk sprites
*/
void	free_player_walk_sprites(t_game *game);

/*
	@brief	set game->player.x/y correponding to player's position
*/
void	set_player_cord(t_game *game);

/*
	@brief	render player on the right position.
*/
void	render_player(t_game *game);

/*
	@brief	move the player if there is nothing in the way
*/
void	player_move(t_game *game, int move);

/*
	@brief	check collision on walls
*/
int		check_collision_y(t_game *game, int move);
int		check_collision_x(t_game *game, int move);
#endif