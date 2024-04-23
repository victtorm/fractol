/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_koch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:12:01 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/23 19:13:19 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_koch(char *str1, char *str2)
{
	ft_strtolower(str1);
	if (str1 == NULL || ft_strlen(str1) != 4)
		return (1);
	while ((*str1 == *str2) && (*str1 != '\0'))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
