/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:11:13 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/23 13:24:24 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


double  ft_pow(double x, double y)
{
    double  result;

    result = 1;
    while(y > 0)
    {
        result *= x;
        y--;
    }
    return (result);
}
double	ato_db(char *str)
{
	int	i;
	double	sin;
    double div;
	double result;
	
    div = 1;
	i = 0;
	sin = 1;
	if (str[i] == 45 || str[i] == 43)
	{
        if (str[i] == 45)
		    sin = -1;
		i++;
	}
	result = (double)(str[i] - '0');
    i += 2;
	while(str[i] != '\0')
	{
		result += (double)((str[i] - '0') / ft_pow(10, div));
		i++;
        div++;
	}
	return (result * sin);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == 43 || str[0] == 45)
		&& (str[1] >= 48) && (str[1] <= 57))
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (0);
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
