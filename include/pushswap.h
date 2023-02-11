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

// utils
void	init_stacks(t_stack *stacks[2], int ac, char **av);
void	new_node(t_stack *last_node, int value);
t_stack	*get_last_node(t_stack *head);
int		lst_size(t_stack *stack);
void	print_res(t_stack *stacks[2]);
void	error_exit(const char *msg);

// operations
void	sa(t_stack *stacks);

#endif
