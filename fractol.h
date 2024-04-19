/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:03:20 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/19 17:51:04 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

#define WIDTH 1000
#define HEIGHT 1000

// COLOR

#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define RED 0xFF0000  
#define GREEN 0x00FF00 
#define BLUE 0x0000FF  

typedef struct s_complex
{
    double  r;
    double  i;
}           t_complex;

/*typedef struct	sfrac_img
{
	void	*image;
	char	*pixels_adr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}           tfrac_img;*/

typedef struct fractol_fractal
{
    char    *set;
    void    *mlx_connection;
    void    *mlx_window;
    void    *img;
    double  r_move;
    double  i_move;
    t_complex  c;
    double  zoom;
    char	*pixels_adr;
    int		bits_per_pixel;
	int		endian;
	int		line_len;
    
}           t_fractal;

// CHECK_SET

// MANDELBROT

int         check_mandelbrot(char *str1, char *str2);
size_t      ft_strlen(const char *src);
void        ft_strtolower(char *str);


// JULIA

int         check_julia(char *str1, char *str2, char *r,  char *i);
int         check_number(char *str);
double	    atodb(char *str);
double      ft_pow(double x, double y);
// START_FRACTOL

void        fractal_init(t_fractal *fractal);
void        start_fractal(t_fractal *fractal);

//  MATH UTILS

t_complex   ft_sum(t_complex z, t_complex c);
t_complex   ft_square(t_complex z);

// FRACTOL_IMG

void        set_start_c(t_fractal *fractal, t_complex z);
void        fractal_img(t_fractal *fractal);
//static void scale_pixel(int x, int y, t_fractal *fractal);
double	    scale(double u_num, double n_min, double n_max, double o_max);
void	    ft_put_pixels(t_fractal *fractal, int x, int y, int color);

// EVENTS

void        fractal_events(t_fractal *fractal);
int         key_imput(int keysym, t_fractal *fractal);
int mouse_imput(int button, int x, int y, t_fractal *fractal);

#endif