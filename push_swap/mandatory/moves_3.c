/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:41:12 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 04:42:21 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_addfront(t_stack **s, t_stack *new)
{
	if (!s || !new)
		return ;
	new->next = *s;
	*s = new;
}

void	ft_rrr(t_stack **s1, t_stack **s2, char *mv)
{
	ft_reverse(s1, NULL);
	ft_reverse(s2, NULL);
	write(1, mv, ft_strlen(mv));
}

static t_stack	*ft_before_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next && s->next->next)
		s = s->next;
	return (s);
}

void	ft_reverse(t_stack **s, char *mv)
{
	t_stack	*tmp;

	tmp = ft_before_last((*s));
	ft_addfront(s, tmp->next);
	tmp->next = NULL;
	ft_index(*s);
	if (mv)
		write(1, mv, ft_strlen(mv));
}
