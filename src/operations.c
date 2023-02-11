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
void	sa(t_stack *stack)
{
	t_stack	*node_1;
	t_stack	*node_2;

	if (stack->next)
	{
		node_1 = stack; // 1
		node_2 = stack->next; //4
		node_1->prev = node_2;
		node_1->next = node_2->next;
		(node_2->next)->prev = node_1;
		node_2->next = node_1;
		node_2->prev = NULL;
		*stack = *node_2;
	}
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
void	sb()
{}
// ss : sa et sb en même temps.
void	ss()
{}
// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
void	pa()
{}
// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
void	pb()
{}
// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
void	ra()
{}
// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
void	rb()
{}
// rr : ra et rb en même temps.
void	rr()
{}
// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
void	rra()
{}
// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.
void	rrb()
{}
// rrr : rra et rrb en même temps.
void	rrr()
{}
