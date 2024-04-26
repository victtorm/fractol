/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:03:20 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/26 12:38:03 by vbritto-         ###   ########.fr       */
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
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

#define WIDTH 700
#define HEIGHT 700

// COLOR

#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define RED 0xFF0000  
#define GREEN 0x00FF00 
#define BLUE 0x0000FF
#define PURPLE  0x8b00ff
#define YELLOW 0xfcff0f


typedef struct s_koch
{
    double  x;
    double  y;
}           t_koch;

typedef struct s_complex
{
    double  r;
    double  i;
}           t_complex;

typedef struct fractol_fractal
{
    struct fractol_fractal *to_fractol;
    //minilibx ptr
    char    *set;
    void    *mlx_connection;
    void    *mlx_window;
    void    *img;
    // complex numbers
    t_complex  c;
    t_complex  j;
    // interacations
    int     inter;
    // zoom and move
    double  r_move;
    double  i_move;
    double  zoom;
    // t_img 
    char	*pixels_adr;
    int		bits_per_pixel;
	int		endian;
	int		line_len;
    // mandelbrot and julia
    bool     maj;
    // color
    int      color_1;
    int      color_2;
    // koch
    t_koch  coord[5];
}           t_fractal;

// CHECK_SET

// MANDELBROT

int         check_mandelbrot(char *str1, char *str2);
size_t      ft_strlen(const char *src);
void        ft_strtolower(char *str);


// JULIA

int         check_julia(char *str1, char *str2, char *r,  char *i);
int         check_number(char *str);
double	    ato_db(char *str);
double      ft_pow(double x, double y);
// START_FRACTOL

void        fractal_init(t_fractal *fractal);
void        start_fractal(t_fractal *fractal);

//  MATH UTILS

t_complex   ft_sum(t_complex z, t_complex c);
t_complex   ft_square(t_complex z);

// FRACTOL_IMG

t_complex	set_start_c(t_fractal *fractal, int x, int y);
void        fractal_img(t_fractal *fractal);
//static void scale_pixel(int x, int y, t_fractal *fractal);
double	    scale(double u_num, double n_min, double n_max, double o_max);
void	    ft_put_pixels(t_fractal *fractal, int x, int y, int color);

// EVENTS
void    change_color(t_fractal *fractal);
int    mouse_position(t_fractal *fractal);
void    fractal_events(t_fractal *fractal);
int     key_imput(int keysym, t_fractal *fractal);
int     mouse_imput(int button, int x, int y, t_fractal *fractal);
void    zoom_in(t_fractal *fractal, int x, int y);
void    zoom_out(t_fractal *fractal, int x, int y);
// KOCH
void	koch(t_fractal *koch, char *set);
int	    check_koch(char *str1, char *str2);
void    start_koch(t_fractal *fractal);
void    init_koch(t_fractal *fractal);
void    init_koch(t_fractal *fractal);

void    koch_events(t_fractal *fractal);
int     koch_key_imput(int keysym, t_fractal *fractal);
int     koch_mouse_imput(int button, int x, int y, t_fractal *fractal);
int     koch_close_window(t_fractal *fractal);

void    koch_img(t_fractal *koch);
void    update_coord(t_koch *m);
void    draw_line(t_fractal *koch, t_koch a, t_koch b);
void    draw_down(t_fractal *koch, t_koch c, t_koch d);
void    draw_up(t_fractal *koch, t_koch c, t_koch d);
void    draw_igual(t_fractal *koch, t_koch c, t_koch d);






#endif