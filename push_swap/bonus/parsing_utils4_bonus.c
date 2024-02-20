/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:57:00 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/13 05:27:24 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	get_len(char **strs, char *sep, int size)
{
	int	len_s;
	int	i;

	len_s = 0;
	i = 0;
	while (i < size)
	{
		len_s += ft_strlen(strs[i]);
		i++;
	}
	len_s += ft_strlen(sep) * (size - 1);
	return (len_s);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_dest;

	len_dest = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len_s;
	char	*str;

	str = NULL;
	if (size <= 0)
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	len_s = get_len(strs, sep, size);
	str = malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (NULL);
	i = 0;
	str[i] = '\0';
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < (size - 1))
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
