/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:09:56 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/20 21:09:56 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void simplify(t_stack **stack, int ac)
{
    int i = 0;
    t_stack *save = *stack;
    t_stack *save_copy = NULL;
    t_stack *temp = NULL;

    // Créer une copie de la liste chaînée save
    save_copy = copy_list(save);

    // Trier la copie
    sort(&save_copy, ac);

    // Parcourir la liste chaînée stack
    while (*stack)
    {
        temp = save_copy;
        i = 0;

        while (temp)
        {
            if ((*stack)->num == temp->num)
            {
                (*stack)->num = i;
                break;
            }
            i++;
            temp = temp->next;
        }
        *stack = (*stack)->next;
    }
    *stack = save;

    // Libérer la mémoire allouée pour la copie de la liste chaînée save
    // ft_lstclear(&save_copy);
}


void    big_sort(t_stack *stacks[2], int ac)
{
    t_stack **save;

    save = &stacks[A];
    simplify(save, ac);
}