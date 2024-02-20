/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:36:21 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 04:42:53 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_a(t_stack **a, t_stack **b, t_stack *bst_elem)
{
	t_stack	*top;

	top = get_top(*a, bst_elem);
	if (get_type(*a, *b, top, bst_elem) == 1)
		two_up(a, b, top, bst_elem);
	else if (get_type(*a, *b, top, bst_elem) == 2)
		two_down(a, b, top, bst_elem);
	else if (get_type(*a, *b, top, bst_elem) == 3)
		up_down(a, b, top, bst_elem);
	else if (get_type(*a, *b, top, bst_elem) == 4)
		down_up(a, b, top, bst_elem);
	ft_push(b, a, "pa\n");
}

static int	check_pos(t_stack *s, int nbr, int size)
{
	int	c;

	c = 0;
	while (1)
	{
		if (s->nbr == nbr)
			break ;
		c++;
		s = s->next;
	}
	if (c > (size / 2))
		return (0);
	return (1);
}

static void	final_sorte(t_stack **a, t_stack *m_nbr, int pos)
{
	while (1)
	{
		if ((*a)->nbr == m_nbr->nbr)
			break ;
		if (pos == 0)
			ft_reverse(a, "rra\n");
		if (pos == 1)
			ft_rotate(a, "ra\n");
	}
}

void	sort_all(t_stack	**stack_a, t_stack	**stack_b, int size)
{
	t_stack	*tmp;
	int		size_b;

	size_b = ft_lt_size(*stack_b);
	while (size_b--)
	{
		set_moves(*stack_a, stack_b);
		push_to_a(stack_a, stack_b, best_elem(*stack_b));
	}
	tmp = min_stack(*stack_a);
	final_sorte(stack_a, tmp, check_pos(*stack_a, tmp->nbr, size));
}
