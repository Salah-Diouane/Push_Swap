/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:24:43 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/20 00:36:07 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	stock_inst(t_stack **stack_a, t_stack **stack_b, char	**res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		res[i] = ft_strjoin_(res[i], "\n");
		if (!res[i])
			exit(EXIT_FAILURE);
		app_instruction(stack_a, stack_b, res[i]);
		i++;
	}
}

static void	finish_fct(char *join, char	**res, t_stack	*stack_a,
	t_stack	*stack_b)
{
	res = ft_split(join, '\n');
	if (!res)
		exit(EXIT_FAILURE);
	stock_inst(&stack_a, &stack_b, res);
	check_if_is_sorted(stack_a, stack_b);
	(ft_free_tab(res), free_stack(stack_a), free_stack(stack_b));
}

static void	protect_join(char	*str)
{
	if (!str)
		free(str);
}

int	main(int arc, char	**arv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*str;
	static char		*join;
	char			**res;

	if (arc > 1)
	{
		stack_a = check_parsing(arc, arv);
		stack_b = NULL;
		while (1)
		{
			str = get_next_line(0);
			if (!str)
			{
				free(str);
				break ;
			}
			join = ft_strjoin_(join, str);
			protect_join(join);
			free(str);
		}
		res = NULL;
		finish_fct(join, res, stack_a, stack_b);
	}
}
