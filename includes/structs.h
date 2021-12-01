/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:21:02 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 20:35:57 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
	int		desloc_x;
	int		desloc_y;
	int		width;
	int		height;
}	t_map;

typedef struct	s_sprite
{
	t_data	up[4];
	t_data	down[4];
	t_data	left[4];
	t_data	right[4];

}	t_sprite;

typedef struct	s_player
{
	t_sprite	sprite;
	int			x;
	int			y;
}	t_player;

typedef struct	s_resources
{
	t_data wall;
	t_data floor;
}	t_resources;

typedef struct s_game
{
	t_vars		vars;
	t_map		map;
	t_resources	resources;
	t_player	player;
	int			width;
	int			height;
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