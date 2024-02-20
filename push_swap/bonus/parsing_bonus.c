/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:17:26 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/20 00:35:40 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	check_duplct(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
	{
		free_stack(stack);
		return (0);
	}
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_check_esp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	ft_empty(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!av[i][0])
			return (0);
		if (!ft_check_esp(av[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*check_parsing(int ac, char **av)
{
	int		i;
	char	**str;
	char	*s;
	t_stack	*stack;

	stack = NULL;
	i = -1;
	if (!ft_empty(av) || av[1][0] == '\0')
		exit(write(2, "Error\n", 6));
	s = ft_strjoin(ac - 1, av + 1, " ");
	if (!s)
		(exit(EXIT_FAILURE));
	str = ft_split(s, ' ');
	if (!str)
		(free(s), exit(EXIT_FAILURE));
	while (str[++i])
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(str[i])));
	if (!stack)
		(free(s), ft_free_tab(str), exit(EXIT_FAILURE));
	if (check_duplct(stack) == 1)
		(free(s), ft_free_tab(str), free_stack(stack),
			exit(write(2, "Error\n", 6)));
	(free(s), ft_free_tab(str));
	return (stack);
}
