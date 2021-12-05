/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:21:02 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 20:42:29 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define POKEMON_AMOUNT 4
# define FALSE 0
# define TRUE 1

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
	int				x;
	int				y;
	double			f_x;
	double			f_y;
	int				direction;
	int				walk_frame;
	int				delay;
	int				walk_frame_animation;
	int				delay_animation;
}	t_player;

typedef struct s_pokemon
{
	int					id;
	double				f_x;
	double				f_y;
	int					walk_frame;
	int					direction;
	int					delay;
	struct s_pokemon	*next;
}	t_pokemon;

typedef struct s_door
{
	double			f_x;
	double			f_y;
	struct s_door	*next;
}	t_door;

typedef struct s_resources
{
	t_data		wall;
	t_data		floor;
	t_data		door[2];
	t_sprite	pokemon_sprites[POKEMON_AMOUNT];
}	t_resources;

typedef struct s_game
{
	t_pokemon	*pokemons;
	t_vars		vars;
	t_map		map;
	t_resources	resources;
	t_player	player;
	t_door		*doors;
	int			getting_poke;
	int			width;
	int			height;
	int			win;
	double		vel;
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