/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:44:11 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 04:43:05 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*best_elem(t_stack *s)
{
	t_stack	*tmp;
	int		min;

	min = s->move;
	tmp = s;
	while (s)
	{
		if (s->move < min)
			min = s->move;
		s = s->next;
	}
	s = tmp;
	while (s)
	{
		if (s->move == min)
			return (s);
		s = s->next;
	}
	return (NULL);
}

int	move_type(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (1);
	if (b <= a && b <= c && b <= d)
		return (2);
	if (c <= a && c <= b && c <= d)
		return (3);
	if (d <= a && d <= b && d <= c)
		return (4);
	return (0);
}

int	get_type(t_stack *a, t_stack *b, t_stack *top, t_stack *tmp)
{
	int	two_up;
	int	two_down;
	int	up_down;
	int	down_up;

	two_up = get_max(top->index, tmp->index);
	two_down = get_max((ft_lt_size(a) - top->index),
			(ft_lt_size(b) - tmp->index));
	up_down = top->index + (ft_lt_size(b) - tmp->index);
	down_up = tmp->index + (ft_lt_size(a) - top->index);
	return (move_type(two_up, two_down, up_down, down_up));
}

void	ft_push(t_stack **s1, t_stack **s2, char *mv)
{
	t_stack	*tmp;

	if (!*s1)
		return ;
	tmp = *s1;
	(*s1) = (*s1)->next;
	tmp->next = *s2;
	(*s2) = tmp;
	ft_index(*s1);
	ft_index(*s2);
	if (mv)
		write(1, mv, ft_strlen(mv));
}
