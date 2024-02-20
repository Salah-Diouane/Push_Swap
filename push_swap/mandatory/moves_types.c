/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:28:23 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 04:14:15 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_up(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem)
{
	while ((*a)->nbr != top->nbr && (*b)->nbr != bst_elem->nbr)
		ft_rr(a, b, "rr\n");
	while ((*b)->nbr != bst_elem->nbr)
		ft_rotate(b, "rb\n");
	while ((*a)->nbr != top->nbr)
		ft_rotate(a, "ra\n");
}

void	two_down(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem)
{
	while ((*a)->nbr != top->nbr && (*b)->nbr != bst_elem->nbr)
		ft_rrr(a, b, "rrr\n");
	while ((*b)->nbr != bst_elem->nbr)
		ft_reverse(b, "rrb\n");
	while ((*a)->nbr != top->nbr)
		ft_reverse(a, "rra\n");
}

void	up_down(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem)
{
	while ((*a)->nbr != top->nbr)
		ft_rotate(a, "ra\n");
	while ((*b)->nbr != bst_elem->nbr)
		ft_reverse(b, "rrb\n");
}

void	down_up(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem)
{
	while ((*a)->nbr != top->nbr)
		ft_reverse(a, "rra\n");
	while ((*b)->nbr != bst_elem->nbr)
		ft_rotate(b, "rb\n");
}
