/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:06:56 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/01 18:02:55 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

double	after_dot(char *str)
{
	double	after_dot;
	int		cnt;

	after_dot = 0;
	cnt = 0;
	while (ft_isdigit(*str) != 0)
	{
		after_dot = (after_dot * 10.0) + (*(str++) - '0');
		cnt++;
	}
	while (cnt-- > 0)
		after_dot /= 10.0;
	return (after_dot);
}

double	ft_atod(char *str)
{
	double	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
		result = (result * 10.0) + (*(str++) - '0');
	if (*(str++) == '.')
		result += after_dot(str);
	return (result * sign);
}
