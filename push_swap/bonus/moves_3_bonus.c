/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:41:12 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/13 10:09:19 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!*s || !(*s)->next)
		return ;
	tmp = ft_lstlast(*s);
	node = *s;
	while (node->next->next)
		node = node->next;
	node->next = NULL;
	if (*s)
		tmp->next = *s;
	*s = tmp;
}

void	ft_rrr(t_stack **s1, t_stack **s2)
{
	ft_reverse(s1);
	ft_reverse(s2);
}
