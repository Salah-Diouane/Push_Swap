/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:40:08 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 04:41:12 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_rr(t_stack **s1, t_stack **s2, char *mv)
{
	ft_rotate(s1, NULL);
	ft_rotate(s2, NULL);
	write(1, mv, ft_strlen(mv));
}

void	ft_rotate(t_stack **s, char *mv)
{
	t_stack	*tmp;

	tmp = *s;
	(*s) = (*s)->next;
	tmp->next = NULL;
	ft_lstlast(*s)->next = tmp;
	ft_index(*s);
	if (mv)
		write(1, mv, ft_strlen(mv));
}
