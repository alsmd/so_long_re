/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:21:02 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/09 16:23:12 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define POKEMON_AMOUNT 8
# define FALSE 0
# define TRUE 1
# define MY_SIZE_T unsigned long int

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map
{
	char	**array;
	t_data	render_map;
	t_data	full_map;
	double	desloc[2];
	double	desloc_x;
	double	desloc_y;
	int		width;
	int		height;
}	t_map;

typedef struct s_sprite
{
	t_data	up[4];
	t_data	down[4];
	t_data	left[4];
	t_data	right[4];

}	t_sprite;

typedef struct s_player
{
	t_sprite		sprite;
	t_data			getting_poke[9];
	t_data			victory[3];
	t_data			lost[4];
	MY_SIZE_T		steps;
	int				move;
	int				walk_frame;
	int				delay;
	int				walk_frame_animation;
	int				delay_animation;
	double			position[2];
	double			speed[2];
	double			direc[2];
}	t_player;

typedef struct s_pokemon
{
	int					id;
	int					walk_frame;
	double				direction[2];
	int					delay;
	double				position[2];
	struct s_pokemon	*next;
}	t_pokemon;

typedef struct s_door
{
	double			position[2];
	struct s_door	*next;
}	t_door;

typedef struct s_enemy
{
	int				walk_frame;
	int				delay;
	int				steps;
	double			direction[2];
	double			position[2];
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_resources
{
	t_data		wall;
	t_data		floor[3];
	t_data		door[2];
	t_data		pokeball;
	t_sprite	pokemon_sprites[POKEMON_AMOUNT];
	t_sprite	enemy;
	t_data		enemy_face;
	t_data		reset_message;
}	t_resources;

typedef struct s_game
{
	t_pokemon	*pokemons;
	t_enemy		*enemies;
	t_enemy		*enemy_found;
	t_vars		vars;
	t_map		map;
	t_resources	resources;
	t_player	player;
	t_door		*doors;
	double		enemy_speed[2];
	int			captured_poke;
	int			getting_poke;
	int			enemy_range;
	int			width;
	int			lost;
	int			height;
	int			win;
	int			restart;
	int			close;
}	t_game;

enum e_status
{
	VALID_MAP,
	WRONG_MAP_EXTENTION,
	MAP_NOT_EXIST,
	WRONG_MAP_FORMAT,
	SERVER_ERROR
};

#endif