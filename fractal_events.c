/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:24 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/19 20:11:47 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int close_window(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free (fractal->mlx_connection);
    exit(1);
}


int mouse_imput(int button, int x, int y, t_fractal *fractal)
{
    (void)x;
    (void)y;
    if (button ==  4)
        fractal->zoom *= 0.98;
    if (button ==  5)
        fractal->zoom *= 1.02 ;
    /*if 
    {
        fractal->c.r = x;
        fractal->c.i = i;
    }*/
    fractal_img(fractal);
    return (0);
}

int key_imput(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        exit(1);
    }
    if (keysym == XK_Up)
        fractal->i_move += (0.8 * fractal->zoom);
    if (keysym == XK_Down)
        fractal->i_move -= (0.8 * fractal->zoom);
    if (keysym == XK_Left)
        fractal->r_move -= (0.8 * fractal->zoom);
    if (keysym == XK_Right)
        fractal->r_move += (0.8 * fractal->zoom);
    if (keysym == XK_KP_Add)
        fractal->zoom *= 1.02;
    if (keysym == XK_KP_Subtract)
        fractal->zoom *= 0.98;
    fractal_img(fractal);
    return (0);
}

void    fractal_events(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_imput, fractal);
    mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_imput, fractal);
    mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_window, fractal);
   // mlx_mouse_hook(fractal->mlx_window, mouse_imput, fractal);
    //mlx_key_hook(fractal->mlx_window, key_imput, fractal);
}