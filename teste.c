
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
