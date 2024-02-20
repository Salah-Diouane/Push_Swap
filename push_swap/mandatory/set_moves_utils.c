/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:50:26 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 04:42:11 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_stack	*min_stack(t_stack *sa)
{
	t_stack	*tmp;
	t_stack	*min_node;

	tmp = sa;
	min_node = sa;
	if (sa == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->nbr < min_node->nbr)
			min_node = tmp;
	}
	return (min_node);
}

t_stack	*max_stack(t_stack *sa)
{
	t_stack	*tmp;
	t_stack	*max_node;

	tmp = sa;
	max_node = sa;
	if (sa == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->nbr > max_node->nbr)
			max_node = tmp;
	}
	return (max_node);
}
