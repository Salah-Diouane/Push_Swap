/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:28:54 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 04:35:02 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	x;

	i = 0;
	s = 1;
	x = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1]))
		s = 44 - str[i++];
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit(write(2, "Error\n", 6));
		if ((x * 10 * s + str[i] - '0') > 2147483647
			|| (x * 10 * s + str[i] - '0') < -2147483648)
			exit(write(2, "Error\n", 6));
		x = x * 10 + str[i] - '0';
		i++;
	}
	return (x * s);
}
