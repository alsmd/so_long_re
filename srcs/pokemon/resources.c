/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:25:59 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/05 19:50:28 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	load_free(t_data *img, char *path1, char *path2, t_game *game)
{
	char	*path;

	path = ft_strjoin(path1, ft_strdup(path2));
	load_img(img, path, game);
	free(path);
}

void	pokemon_sprites(t_game *game)
{
	t_sprite	*sprite;
	int			index;
	char		*src;
	char		*src_pk;

	index = 0;
	while (index < POKEMON_AMOUNT)
	{
		src = ft_strdup("./assets/imgs/pokemons/");
		src_pk = ft_strjoin(src, ft_itoa(index));
		sprite = &game->resources.pokemon_sprites[index];
		load_free(&sprite->down[0], ft_strdup(src_pk), "/down_0.xpm", game);
		load_free(&sprite->down[1], ft_strdup(src_pk), "/down_1.xpm", game);
		load_free(&sprite->up[0], ft_strdup(src_pk), "/up_0.xpm", game);
		load_free(&sprite->up[1], ft_strdup(src_pk), "/up_1.xpm", game);
		load_free(&sprite->left[0], ft_strdup(src_pk), "/left_0.xpm", game);
		load_free(&sprite->left[1], ft_strdup(src_pk), "/left_1.xpm", game);
		load_free(&sprite->right[0], ft_strdup(src_pk), "/right_0.xpm", game);
		load_free(&sprite->right[1], ft_strdup(src_pk), "/right_1.xpm", game);
		free(src_pk);
		index++;
	}
}

void	free_pokemon_sprites(t_game *game)
{
	t_sprite	*sprite;
	int			index;
	t_pokemon	*tmp;

	index = 0;
	while (index < POKEMON_AMOUNT)
	{
		sprite = &game->resources.pokemon_sprites[index];
		mlx_destroy_image(game->vars.mlx, sprite->down[0].img);
		mlx_destroy_image(game->vars.mlx, sprite->down[1].img);
		mlx_destroy_image(game->vars.mlx, sprite->up[0].img);
		mlx_destroy_image(game->vars.mlx, sprite->up[1].img);
		mlx_destroy_image(game->vars.mlx, sprite->left[0].img);
		mlx_destroy_image(game->vars.mlx, sprite->left[1].img);
		mlx_destroy_image(game->vars.mlx, sprite->right[0].img);
		mlx_destroy_image(game->vars.mlx, sprite->right[1].img);
		index++;
	}
	while (game->pokemons)
	{
		tmp = game->pokemons->next;
		free(game->pokemons);
		game->pokemons = tmp;
	}
}

void	new_pokemon(t_game *game, int x, int y)
{
	t_pokemon	*begin;
	t_pokemon	*new_pokemon;

	new_pokemon = (t_pokemon *) ft_calloc(1, sizeof(t_pokemon));
	new_pokemon->id = (x * y) % POKEMON_AMOUNT;
	new_pokemon->f_x = x;
	new_pokemon->f_y = y;
	begin = game->pokemons;
	while (begin && begin->next)
		begin = begin->next;
	if (!begin)
		game->pokemons = new_pokemon;
	else
		begin->next = new_pokemon;
}
