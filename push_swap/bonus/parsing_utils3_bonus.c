/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 08:55:06 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/18 20:47:34 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_lt_size(t_stack	*s)
{
	int	cmp;

	cmp = 0;
	while (s)
	{
		cmp++;
		s = s->next;
	}
	return (cmp);
}

t_stack	*ft_lstnew(int data)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
	{
		free_stack(b);
		exit(EXIT_FAILURE);
	}
	b -> nbr = data;
	b -> index = 0;
	b -> next = NULL;
	return (b);
}

void	ft_lstadd_back(t_stack **lst, t_stack *lst_new)
{
	t_stack	*tmp;

	if (!lst || !lst_new)
		return ;
	if (!*lst)
	{
		*lst = lst_new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst_new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
