/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:27:56 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/18 20:28:19 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[i] == p2[i] && (p1[i] != '\0' && p2[i] != '\0'))
		i++;
	return (p1[i] - p2[i]);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !stack_a->next)
		return (1);
	tmp = stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	app_instruction(t_stack	**stack_a, t_stack	**stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa\n"))
		ft_push(stack_b, stack_a);
	else if (!ft_strcmp(str, "pb\n"))
		ft_push(stack_a, stack_b);
	else if (!ft_strcmp(str, "ra\n"))
		ft_rotate(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		ft_rotate(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra\n"))
		ft_reverse(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_reverse (stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
		ft_rrr(stack_a, stack_b);
	else
		exit(write(2, "Error\n", 6));
}

bool	stack_is_empty(t_stack	*stack)
{
	return (stack == NULL);
}

void	check_if_is_sorted(t_stack	*stack_a, t_stack	*stack_b)
{
	if (is_sorted(stack_a) && stack_is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
