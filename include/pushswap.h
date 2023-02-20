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
	int             (*get_prev_count)(struct s_stack*);

}			t_stack;

// ########################
// - - - - sort - - - - 
// ########################
void    small_sort(t_stack *stacks[2], int ac);
void    big_sort(t_stack *stacks[2], int ac);

// ########################
// - - - - utils - - - - 
// ########################
void	sort(t_stack **stack, int ac);
t_stack *get_min_value(t_stack *tail);
void	print_res(t_stack *stacks[2]);
void	error_exit(const char *msg);
int 	has_duplicates(int argc, char *argv[]);
t_stack *copy_list(t_stack *list);

// ########################
// - - - - lists_utils - - - - 
// ########################
void	parse_stack_A(t_stack **stack, int ac, char **av);
t_stack *add_value_back(t_stack *node, int value);
t_stack	*get_last_node(t_stack *tail);
t_stack	*get_first_node(t_stack *head);
int		lst_size(t_stack *stack);
int 	get_prev_count(t_stack *stack);

// ########################
// - - - operations - - -
// ########################
// -> sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
//Ne fait rien s’il n’y en a qu’un ou aucun.
int		sa(t_stack **stack);
// -> sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
int		sb(t_stack **stack);
// -> ss : sa et sb en même temps.
int		ss(t_stack *stacks[2]);

// -> pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
int		pa(t_stack **stack_A, t_stack **stack_B);
// -> pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
int		pb(t_stack **stack_A, t_stack **stack_B);

// -> ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
int		ra(t_stack **stack);
// -> rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
int		rb(t_stack **stack_B);
// -> rr : ra et rb en même temps.
int		rr(t_stack **stack_A, t_stack **stack_B);

// -> rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
int		rra(t_stack **stack);
// -> rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.
int		rrb(t_stack **stack_B);
// -> rrr : rra et rrb en même temps.
int		rrr(t_stack **stack_A, t_stack **stack_B);


#endif
