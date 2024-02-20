/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:40:08 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/14 23:17:38 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_rr(t_stack **s1, t_stack **s2)
{
	ft_rotate(s1);
	ft_rotate(s2);
}

void	ft_rotate(t_stack **s)
{
	t_stack	*tmp;

	if (*s)
	{
		tmp = *s;
		(*s) = (*s)->next;
		tmp->next = NULL;
		ft_lstlast(*s)->next = tmp;
	}
}

void	ft_push(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	if (!*s1)
		return ;
	tmp = *s1;
	(*s1) = (*s1)->next;
	tmp->next = *s2;
	(*s2) = tmp;
}
