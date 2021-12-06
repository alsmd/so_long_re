/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:16:24 by flda-sil          #+#    #+#             */
/*   Updated: 2021/12/06 02:28:44 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "structs.h"

/*
	@brief	Load a image xpm in a object t_data
*/
void	load_img(t_data *img, char *path, t_game *game);

/*
	@brief	Create a new image object with dimensions w and h
*/
void	create_img(t_data *img, int w, int h, t_game *game);

/*
	@brief	Alocates memory dynamically
*/
void	*ft_calloc(size_t nmemb, size_t size);

/*
	@brief	Converts a number to a string
*/
char	*ft_itoa(int n);

/*
	@brief	Concatenate src to the final of dest until a null or /n is found
			in src
*/
void	ft_strcat(char *dest, char *src);

int		ft_strlen(const char *s);

/*
	@brief	Cut and return a string's part	
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		is_in(char *str, char c);

/*
	@brief	put a pixel on x and y coordinate of the image
*/
void	put_pixel(t_data *data, int x, int y, int color);

/*
	@brief	get a pixel of an specif coordinate
*/
int		get_pixel(t_data *data, int x, int y);

/*
	@param	info[0]/info[1]	is the x and y of where the cut will be
							done in src.		
	@param	info[2]/info[3]	is the width and height that we'll be getting
							from src.		
	@brief					Cut a part of the image src and paste in the
							image dest.
*/
void	copy_img_from(t_data *dest, t_data *src, int info[4]);

/*
	@param	info[0]/info[1]	is the x and y of where the paste will be done
							in dest.
	@param	info[2]/info[3]	is the width and height that we'll be getting
							from src.
	@brief					Paste the image src in a specific coordinate
							fo dest.
*/
void	copy_img_to(t_data *dest, t_data *src, int info[4]);

/*
	@brief	Returns a string that is the concatenation of s1 and s2,
			then use free() on s1 and s2
*/
char	*ft_strjoin(char *s1, char *s2);

/*
	@brief	check if str just has the char c
*/
int		only_has(char *str, char c);

/*
	@brief	Returns 0 if str has a char besides \0 and \n, it returns 1
			otherwise
*/
int		is_empty(char *str);

/*
	@brief	tranform the parameters in an array
*/
int		*to_array(int x, int y, int w, int h);

/*
	@brief	if float number has something after dotte it will be rouded to
			the next int number and returned
*/
int		round_to_top(double n);

double	my_abs(double n);

void	ft_bzero(void *s, size_t n);

char	*ft_strdup(const char *s);

/*
	@brief	Returns a color with a quantity of red green and blue
*/
int	create_rgb(int r, int g, int b);

/*
	@brief	Darkens a color using qnt_shade, qnt_shade can be a number
			between 0 and 1. 0 to the darkest and 1 to normal.
*/
int	get_color_shade(int color, double qnt_shade);

#endif