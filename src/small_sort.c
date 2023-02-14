/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:39:21 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/14 13:39:21 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int sort_three_values(t_stack *stacks[2])
{
    // 2 1 3
    if (stacks[A]->num > stacks[A]->next->num 
        && stacks[A]->next->num < stacks[A]->next->next->num
        && stacks[A]->num < stacks[A]->next->next->num)
    {
        sa(&stacks[A]);
        printf("SA Operated ! \n");
    }
    // 3 2 1
    if (stacks[A]->num > stacks[A]->next->num 
        && stacks[A]->next->num > stacks[A]->next->next->num
        && stacks[A]->num > stacks[A]->next->next->num)
    {
        sa(&stacks[A]);
        rra(&stacks[A]);
    }
    // 3 1 2
    if (stacks[A]->num > stacks[A]->next->num 
        && stacks[A]->next->num < stacks[A]->next->next->num
        && stacks[A]->num > stacks[A]->next->next->num)
    {
        ra(&stacks[A]);
    }
    // 1 3 2
    if (stacks[A]->num < stacks[A]->next->num 
        && stacks[A]->next->num > stacks[A]->next->next->num
        && stacks[A]->num < stacks[A]->next->next->num)
    {
        sa(&stacks[A]);
        ra(&stacks[A]);
    }
    // 2 3 1
    if (stacks[A]->num < stacks[A]->next->num 
        && stacks[A]->next->num > stacks[A]->next->next->num
        && stacks[A]->num > stacks[A]->next->next->num)
    {
        rra(&stacks[A]);
    }
    return (0);

}

// void    sort_five_values(t_stack *stacks[2])
// {}

void    small_sort(t_stack *stacks[2], int ac)
{
    if (ac == 3)
        sort_three_values(stacks);
    // else if (ac == 5)
        // sort_five_values(stacks);
}