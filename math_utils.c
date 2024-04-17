/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:47:24 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/17 13:18:24 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
MANLDELBROT fcution
z = z^2 + c

*/

t_complex	ft_sum(t_complex z, t_complex c)
{
	t_complex	result;

	result.r = z.r + c.r;
	result.i = z.i + c.i;
	return (result);
}

/*
SQUARE
Complex Z number is z.real + z.imaginary
z^2 = (z.real + z.imaginary)^2 = 
= z.real^2 + 2*z.real*z.imaginary + z.imaginary^2 (imaginary number ^2 = -1)
real numbers = z.real^2 - z.imaginary^2 
(now this imaginary number is a real number)
imaginary numbers = 2*z.real*z.imaginary
*/
t_complex	ft_square(t_complex z)
{
	t_complex	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = 2 * z.r * z.i;
	return (result);
}
