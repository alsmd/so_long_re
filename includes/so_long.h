/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:22:13 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/10 00:32:29 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define FRAMES 25
# define DARKNESS 0.5
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
# define SPACE 32
# define APROX_MAX 0.9
# define APROX_MIN 0.0001
# include "get_next_line.h"
# include "utils.h"
# include "vetor.h"
# include <mlx.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
	@brief	Start the game
*/
int		init(char *map, t_game *game);

//MAP
/*
	@brief	Will make the checks corresponding to the map and
			keep the map in an array
*/
int		map_check(t_game *game, char *map_name);

/*
	@brief	map_check's helper
*/
void	check_element(t_game *game, int y, int *check);

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
	@brief	Check if coordenates x and y is on screen.
			x and y must  not be in pixels but in blocks instead
*/
int		is_on_screen(t_game *game, double x, double y);

/*
	@brief Create pokemons objects corresponding to the items present inside
			the map or door object corresponding to the doors inside the map.
*/
void	create_elements(t_game *game);

/*
	@brief	Render door if it is inside visible screen.
*/
void	render_door(t_game *game);

/*
	@brief	Draw a pokeball for each captured pokemon.
*/
void	draw_icon(t_game *game);

/*
	@brief	Check door collition
*/
void	check_door_collition(t_game *game);

/*
	@brief	Free game resources.
*/
void	free_resources(t_game *game);

/*
	@brief Checks if a and b have an aproximated value
*/
int		aprox(double a, double b);

int		round_up(double n);
int		round_down(double n);

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

void	change_frame(t_game *game, int move);

int		can_move_cam(t_game *game);

int		has_player_collition(t_game *game, double pos[2]);

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
int		check_collision(t_game *game, double direction[2], double position[2]);

//POKEMON

/*
	@brief	Load pokemon's sprites
*/
void	pokemon_sprites(t_game *game);

/*
	@brief	Frees pokemon's sprites
*/
void	free_pokemon_sprites(t_game *game);

/*
	@brief Add a new pokemon to the list;
*/
void	new_pokemon(t_game *game, int x, int y);

/*
	@brief If pokemon is on screen it will be draw
*/
void	render_pokemon(t_game *game);

/*
	@brief Check if player is in collition with a pokemon
*/
int		check_poke_collition(t_game *game);

//ENEMY
/*
	@brief Load enemy sprites.
*/
void	enemy_sprites(t_game *game);

/*
	@brief Free enemy sprites.
*/
void	free_enemy_sprites(t_game *game);

/*
	@brief Create enemies.
*/
void	create_enemies(t_game *game);

/*
	@brief Render enemies.
*/
void	render_enemy(t_game *game);

/*
	@brief Check Enemy collition with player.
*/
int		check_enemy_collition(t_game *game);

/*
	@brief Check if enemy can make a moviment x or y.
*/
int		enemy_collision_x(t_game *game, int move, t_enemy *enemy);
int		enemy_collision_y(t_game *game, int move, t_enemy *enemy);

/*
	@brief Move all the enemies present inside the game.
*/
void	move_enemies(t_game *game);

/*
	@brief	Move the enemy that detected the player towards him
*/
void	move_enemy(t_game *game);

/*
	@brief	Check if enemy or its range is inside de screen
*/
int		enemy_range_on_screen(t_game *game, double x, double y);

void	draw_enemy_lost(t_game *game);

#endif