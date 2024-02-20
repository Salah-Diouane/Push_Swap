/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:27:25 by sdiouane          #+#    #+#             */
/*   Updated: 2024/02/19 03:00:27 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <libc.h>
# include <stdbool.h>

typedef struct t_stack
{
	int				nbr;
	int				moves;
	int				index;
	struct t_stack	*next;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//get_next_line :
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *s);
int		find(char *s, char c);
char	*ft_join(char *dest, char *s1, char *s2);
char	*ft_strjoin_(char *start, char *buff);
char	*ft_read_line(char *s);
char	*move_s(char *s);
char	*get_next_line(int fd);

//moves :
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ft_push(t_stack **s1, t_stack **s2);
void	ft_index(t_stack *s);
int		ft_strlen(char *str);
void	ft_rr(t_stack **s1, t_stack **s2);
void	ft_rotate(t_stack **s);
void	ft_rrr(t_stack **s1, t_stack **s2);
void	ft_reverse(t_stack **s);

//parsing :
int		check_duplct(t_stack *stack);
int		ft_check_esp(char *str);
int		ft_empty(char **av);
t_stack	*check_parsing(int ac, char **av);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
void	ft_free_tab(char **tab);
char	**ft_split(char	*s, char c);
char	*ft_strjoin(int size, char **strs, char *sep);

//stack :
int		ft_lt_size(t_stack	*s);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	free_stack(t_stack *head);
int		is_sorted(t_stack *stack_a);
bool	stack_is_empty(t_stack	*stack);
void	check_if_is_sorted(t_stack	*stack_a, t_stack	*stack_b);

//instruction :
void	app_instruction(t_stack	**stack_a, t_stack	**stack_b, char *str);

#endif
