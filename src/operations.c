/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:31:54 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/11 17:02:49 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
//Ne fait rien s’il n’y en a qu’un ou aucun.
void	sa(t_stack **stack)
{
	// t_stack *node_1 = stack->next;
	// t_stack *node_2 = node_1->next;
	// t_stack *tmp = node_1;
	// node_1->prev = node_2;
	// node_2->prev = stack;
	// node_1->next = node_2->next;
	// if (node_2->next)
	// 	node_2->next->prev = node_1;
	// node_2->next = tmp;
	// stack->next = node_2;


	t_stack *node_1 = *stack;
	t_stack *node_2 = node_1->next;
	node_1->prev = node_2;
	node_2->prev = NULL;
	node_1->next = node_2->next;
	if (node_1->next)
		node_1->next->prev = node_1;
	node_2->next = node_1;
	*stack = node_2;
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
void	sb(t_stack **stack)
{
	sa(stack);
}
// ss : sa et sb en même temps.
void	ss(t_stack *stacks[2])
{
	sa(&stacks[A]);
	sb(&stacks[B]);
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
void	pa(t_stack **stack_A, t_stack **stack_B)
{
	t_stack *temp;

	if (*stack_B)
	{
		(*stack_B)->next->prev = NULL;
		temp = *stack_B;
		*stack_B = (*stack_B)->next;
		temp->next = *stack_A;
		(*stack_A)->prev = temp;
		*stack_A = temp;
	}
}
// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
void	pb(t_stack **stack_A, t_stack **stack_B)
{
	if (*stack_A)
		pa(stack_B, stack_A);
}
// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
void	ra(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = get_last_node(*stack);
	temp->prev->next = temp;
}
// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
void	rb(t_stack **stack_B)
{
	ra(stack_B);
}
// rr : ra et rb en même temps.
void	rr(t_stack **stack_A, t_stack **stack_B)
{
	ra(stack_A);
	rb(stack_B);
}
// // rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// // la pile a. Le dernier élément devient le premier.
// void	rra(t_stack **stack)
// {}
// // rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// // la pile b. Le dernier élément devient le premier.
// void	rrb(t_stack **stack_B)
// {}
// // rrr : rra et rrb en même temps.
// void	rrr(t_stack **stack_A, t_stack **stack_B)
// {}
