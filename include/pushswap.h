/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:33:36 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/10 16:25:43 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

// # include <sys/wait.h>
// # include <fcntl.h>
# include "../libft/include/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define A 0
# define B 1

// typedef struct s_stack	t_stack;
typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
	struct s_stack	*next;

}			t_stack;

// main

// sort
void    small_sort(t_stack *stacks[2], int ac);

// utils
void	parse_stack_A(t_stack **stack, int ac, char **av);
t_stack *add_value_back(t_stack *node, int value);
t_stack	*get_last_node(t_stack *head);
int		lst_size(t_stack *stack);
void	print_res(t_stack *stacks[2]);
void	error_exit(const char *msg);
int 	has_duplicates(int argc, char *argv[]);
// operations
int		sa(t_stack **stack);
int		sb(t_stack **stack);
int		ss(t_stack *stacks[2]);

int		pa(t_stack **stack_A, t_stack **stack_B);
int		pb(t_stack **stack_A, t_stack **stack_B);

int		ra(t_stack **stack);
int		rb(t_stack **stack_B);
int		rr(t_stack **stack_A, t_stack **stack_B);

int		rra(t_stack **stack);
int		rrb(t_stack **stack_B);
int		rrr(t_stack **stack_A, t_stack **stack_B);


#endif
