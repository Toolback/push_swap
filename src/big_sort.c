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

void    radix_sort(t_stack *stacks[2], int ac)
{
    int i;
    int j;
    int num;
    int size;
    int max_num;
    int max_bits;
    
    i = 0;
    size = ac;
    max_num = size - 1;
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        ++max_bits;
    while (i < max_bits)
    {
    j = 0;
        while (j < size)
        {
            num = stacks[A]->num;
            if (((num >> i) & 1) == 1) 
                ra(&stacks[A]);
            else
                pb(&stacks[A], &stacks[B]);
            j++;
        }
        while (stacks[B])
            pa(&stacks[A], &stacks[B]);
        i++;
    }
}

void    big_sort(t_stack *stacks[2], int ac)
{
    simplify(&stacks[A], ac);
    radix_sort(stacks, ac);
}