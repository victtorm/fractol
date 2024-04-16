/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:27:18 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/16 19:23:33 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_strtolower(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
			*str += 32;
		str++;
	}
}

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int	check_mandelbrot(char *str1, char *str2)
{
	ft_strtolower(str1);
	if (str1 == NULL || strlen(str1) != 10)
		return (1);
	while ((*str1 == *str2) && (*str1 != '\0'))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
