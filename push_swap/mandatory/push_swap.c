/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:02:29 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 08:50:54 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_devise_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lt_size(*stack_a);
	while (size--)
	{
		ft_push(stack_a, stack_b, "pb\n");
		if (size == 2)
			break ;
	}
}

int	main(int arc, char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (arc > 1)
	{
		stack_a = check_parsing(arc, arv);
		size = ft_lt_size(stack_a);
		stack_b = NULL;
		if (!is_sorted(stack_a))
		{
			if (ft_lt_size(stack_a) == 2)
				sa(&stack_a);
			else if (ft_lt_size(stack_a) == 3)
				ft_sort_three(&stack_a);
			else if (ft_lt_size(stack_a) == 5)
				ft_sort_five(&stack_a, &stack_b);
			else
			{
				ft_devise_stack(&stack_a, &stack_b);
				sort_all(&stack_a, &stack_b, size);
			}
		}
		(free_stack(stack_a), free_stack(stack_b));
	}
}
