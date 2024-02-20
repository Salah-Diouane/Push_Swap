/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:43:56 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/20 00:56:46 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_top(t_stack *a, t_stack *b)
{
	if (b->nbr < min_stack(a)->nbr || b->nbr > max_stack(a)->nbr)
		return (min_stack(a));
	if (a->nbr > b->nbr && ft_lstlast(a)->nbr < b->nbr)
		return (a);
	while (a && a->next)
	{
		if (a->nbr < b->nbr && a->next->nbr > b->nbr)
			return (a->next);
		a = a->next;
	}
	return (NULL);
}

int	best_move(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	if (b <= a && b <= c && b <= d)
		return (b);
	if (c <= a && c <= b && c <= d)
		return (c);
	if (d <= a && d <= b && d <= c)
		return (d);
	return (0);
}

int	get_move(t_stack *a, t_stack *b, t_stack *top, t_stack *tmp)
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
	return (best_move(two_up, two_down, up_down, down_up));
}

void	set_moves(t_stack *a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*top_of_a;

	tmp = *b;
	while (tmp)
	{
		top_of_a = get_top(a, tmp);
		tmp->move = get_move(a, *b, top_of_a, tmp) + 1;
		tmp = tmp->next;
	}
}
