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
int	sa(t_stack **stack)
{
	if ((*stack)->next)
	{
		t_stack *node_1 = *stack;
		t_stack *node_2 = node_1->next;
		node_1->prev = node_2;
		node_2->prev = NULL;
		node_1->next = node_2->next;
		if (node_1->next)
			node_1->next->prev = node_1;
		node_2->next = node_1;
		*stack = node_2;
		return (1);
	}
	else
	{
		ft_printf("sa : No Stack Allocated");
		return (0);
	} 
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
int	sb(t_stack **stack)
{
	if (!sa(stack))
	{
		ft_printf("sb : No Stack Allocated");
		return (0);
	}
	return (1);
}
// ss : sa et sb en même temps.
int	ss(t_stack *stacks[2])
{
	if (!sa(&stacks[A]) || sb(&stacks[B]))
	{
		ft_printf("ss : No Stack Allocated");
		return (0);
	}
	return (1);
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
int	pa(t_stack **stack_A, t_stack **stack_B)
{
	t_stack *temp;

	if (*stack_B)
	{
		temp = *stack_B;
		if ((*stack_B)->next)
		{
			(*stack_B)->next->prev = NULL;
			*stack_B = (*stack_B)->next;
		}
		else 
			*stack_B = NULL;
		if (*stack_A)
		{
			temp->next = *stack_A;
			(*stack_A)->prev = temp;
			*stack_A = temp;
			return (1);
		}
		else
		{
			temp->next = NULL;
			temp->prev = NULL;
			*stack_A = temp;
			return (1);
		}
	}
	else 
	{
		ft_printf("pa : No Stack Allocated");
		return (0);
	}
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
int	pb(t_stack **stack_A, t_stack **stack_B)
{
	if (!pa(stack_B, stack_A))
		return (0);
	return (1);
}

// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
int	ra(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
	{
		ft_printf("ra : No Stack Allocated, or only one element");
		return (0);
	}
	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = get_last_node(*stack);
	temp->prev->next = temp;
	return (1);
}

// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
int	rb(t_stack **stack_B)
{
	if (!ra(stack_B))
		return (0);
	return (1);
}

// rr : ra et rb en même temps.
int	rr(t_stack **stack_A, t_stack **stack_B)
{
	if (!ra(stack_A) || !rb(stack_B))
		return (0);
	return (1);
}

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
int	rra(t_stack **stack)
{
	t_stack *last_node;
	t_stack *temp;
	t_stack *prev;

	if (!*stack || !(*stack)->next)
	{
		ft_printf("rra : No Stack Allocated, or only one element");
		return (0);
	}
	last_node = get_last_node(*stack);
	prev = last_node->prev; 
	last_node->prev = NULL;
	last_node->next = (*stack)->next;
	(*stack)->next->prev = last_node;
	temp = *stack;
	temp->next = NULL;
	temp->prev = prev;
	*stack = last_node;
	return (1);
}

// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.
int	rrb(t_stack **stack_B)
{
	if (!rra(stack_B))
		return (0);
	return (1);
}

// rrr : rra et rrb en même temps.
int	rrr(t_stack **stack_A, t_stack **stack_B)
{
	if (!rra(stack_A) || !rrb(stack_B))
		return (0);
	return (1);
}
