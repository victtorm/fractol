/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:47:24 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/16 18:58:55 by vbritto-         ###   ########.fr       */
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

	result.real = z.real + c.real;
	result.imaginary = z.imaginary + c.imaginary;
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

	result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}
