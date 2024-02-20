/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:57:22 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/18 20:47:41 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <libc.h>

typedef struct t_stack
{
	int				nbr;
	int				index;
	int				move;
	struct t_stack	*next;
}	t_stack;

//parsing :
int		ft_atoi(const char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_isspace(int c);
void	ft_free_tab(char **tab);
char	**ft_split(char	*s, char c);
int		check_duplct(t_stack *stack);
int		ft_check_esp(char *str);
int		ft_empty(char **av);
t_stack	*check_parsing(int ac, char **av);
int		ft_strlen(char *str);

//lst :
t_stack	*ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *lst_new);
t_stack	*ft_lstlast(t_stack *lst);
void	free_stack(t_stack *head);
int		ft_lt_size(t_stack	*s);
void	ft_devise_stack(t_stack **stack_a, t_stack	**stack_b);

//moves :
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **s1, t_stack **s2, char *mv);
void	ft_rotate(t_stack **s, char *mv);
void	ft_rrr(t_stack **s1, t_stack **s2, char *mv);
void	ft_reverse(t_stack **s, char *mv);
void	two_up(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem);
void	two_down(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem);
void	up_down(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem);
void	down_up(t_stack **a, t_stack **b, t_stack *top, t_stack *bst_elem);

//sorting : 
int		is_sorted(t_stack *stack);
void	ft_sort_five(t_stack	**stack_a, t_stack	**stack_b);
void	sort_all(t_stack	**stack_a, t_stack	**stack_b, int size);
void	set_moves(t_stack *a, t_stack **b);
int		get_move(t_stack *a, t_stack *b, t_stack *top, t_stack *tmp);
int		best_move(int a, int b, int c, int d);
t_stack	*get_top(t_stack *a, t_stack *b);
t_stack	*max_stack(t_stack *sa);
t_stack	*min_stack(t_stack *sa);
int		get_max(int a, int b);
t_stack	*best_elem(t_stack *s);
void	ft_sort_three(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack	**stack_b);
void	ft_push(t_stack **s1, t_stack **s2, char *mv);
int		get_type(t_stack *a, t_stack *b, t_stack *top, t_stack *tmp);
int		move_type(int a, int b, int c, int d);
t_stack	*best_elem(t_stack *s);

//indexing :
void	ft_index(t_stack	*s);

#endif