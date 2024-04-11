/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:54:08 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/11 18:43:05 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <stdio.h>

#define MLX_ERROR
#define WIDTH 1000
#define HEIGHT 1000


typedef struct t_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}           t_mlx_data;

int handle_imput(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    return (0);
}



int main()
{
    t_mlx_data  data;
    int     x;
    int     y;
    

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "windon1");
    x = WIDTH * 0.1;
    y = HEIGHT * 0.1;

    while (x < WIDTH * 0.9)
    {
        while (y < HEIGHT * 0.9)
        {
            mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, rand () % 0x1000000);
            y++;
        }
        y = HEIGHT * 0.1;
        x++;
    }

    mlx_key_hook(data.win_ptr, handle_imput, &data);
    
    mlx_loop(data.mlx_ptr);
}