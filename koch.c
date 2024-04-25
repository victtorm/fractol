/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:12:01 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/24 17:01:39 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	koch(t_fractal *koch, char *set)
{
	koch->set = set;
	init_koch(koch);
	koch_events(koch);
	koch_img(koch);
	mlx_loop(koch->mlx_connection);

}



