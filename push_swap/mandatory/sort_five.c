/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:48:27 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/17 00:05:39 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min_three(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

static t_stack	*find_noued(t_stack	*a, int min_nbr)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr == min_nbr)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	last_instruction(t_stack *tmp, t_stack **stack_b)
{
	ft_sort_three(&tmp);
	ft_push(stack_b, &tmp, "pa\n");
	ft_push(stack_b, &tmp, "pa\n");
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	tmp = *stack_a;
	while (++i < 2)
	{
		if (find_noued(tmp, ft_min_three(tmp)) != NULL)
		{
			if (find_noued(tmp, ft_min_three(tmp))->index
				<= ft_lt_size(tmp) / 2)
			{
				while (tmp->nbr != find_noued(tmp, ft_min_three(tmp))->nbr)
					ft_rotate(&tmp, "ra\n");
				ft_push(&tmp, stack_b, "pb\n");
			}
			else
			{
				while (tmp->nbr != ft_min_three(tmp))
					ft_reverse(&tmp, "rra\n");
				ft_push(&tmp, stack_b, "pb\n");
			}
		}
	}
	last_instruction(tmp, stack_b);
}
