/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:03:20 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/13 18:40:03 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minilibx/mlx_linux/mlx_int.h"
# include "minilibx/mlx_linux/mlx.h"
# include <math.h>

#define WIDTH 1000
#define HEIGHT 1000


typedef struct s_complex
{
    double  real;
    double  imaginary;
}           t_complex;

typedef struct s_fractal
{
    char    *set;
    void    *mlx_connection;
    void    *mlx_windon;
    t_img   img;
    double  real_move;
    double  imaginary_move;
    
    
}           t_fractal;




// STRINGS_UTILS

int check_mandelbrot(char *str1, char *str2);
int check_julia(char *str1, char *str2, char *r,  char *i);
size_t	ft_strlen(const char *src);
void    ft_strtolower(char *str);
int     check_number(char *str);