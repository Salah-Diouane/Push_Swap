/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:05:03 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/17 00:05:49 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_three(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

void	ft_sort_three(t_stack **stack)
{
	int	max;

	max = ft_max_three(*stack);
	if ((*stack)->nbr == max)
	{
		ft_rotate(stack, "ra\n");
	}
	else if ((*stack)->next->nbr == max)
		ft_reverse(stack, "rra\n");
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}
