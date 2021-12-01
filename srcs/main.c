/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:56:58 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/01 20:40:07 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <mlx.h>

//Isso é um objeto que representa nossa imagem
//Podemos instanciar quantas imagens quisermos com esse modelo
/* typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data; */


/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;
	int		bytes;

	bytes = (data->bits_per_pixel / 8);
	dest = data->addr + (y * data->line_length + x * bytes);
	*(unsigned int *)dest = color;
}
 */
/* int	main2(void)
{
	t_vars	vars;
	t_data	player;
	t_data	background;

	vars.mlx = mlx_init();//inicia nosso servidor e armazena em vars.mlx
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Nosso Teste!"); //cria uma nova janela e armazena em vars.win
	
	mlx_loop(vars.mlx);
	return (0);
} */

int	main(int argc, char *argv[])
{
	int		status;
	t_game	game;

	status = map_check_controller(&game, "./maps/simple.ber");
	if (status != VALID_MAP)
		return (print_message_status(status));
	status = game_config(&game);
	if (status == SERVER_ERROR)
		return (print_message_status(status));
	//game_init(game);
	return (0);
}
