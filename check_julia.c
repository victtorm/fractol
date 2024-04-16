/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:11:13 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/16 19:21:57 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_number(char *str)
{
	int	i;

	i = 2;
	if ((str[0] == 43 || str[0] == 45)
		&& (str[1] >= 48) && (str[1] <= 57))
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	check_julia(char *str1, char *str2, char *r, char *i)
{
	ft_strtolower(str1);
	if (str1 == NULL || ft_strlen(str1) != 5 || !check_number(r)
		|| !check_number(i))
		return (1);
	while ((*str1 == *str2) && (*str1 != '\0'))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
