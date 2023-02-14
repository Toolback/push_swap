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

int sort_two_values(t_stack **stack)
{
    if ((*stack)->num > (*stack)->next->num)
    {
        sa(stack);
    }
    return (0);
}
int sort_three_values(t_stack **stack)
{
    // 2 1 3
    if ((*stack)->num > (*stack)->next->num 
        && (*stack)->next->num < (*stack)->next->next->num
        && (*stack)->num < (*stack)->next->next->num)
    {
        sa(stack);
        printf("SA Operated ! \n");
    }
    // 3 2 1
    if ((*stack)->num > (*stack)->next->num 
        && (*stack)->next->num > (*stack)->next->next->num
        && (*stack)->num > (*stack)->next->next->num)
    {
        sa(stack);
        rra(stack);
    }
    // 3 1 2
    if ((*stack)->num > (*stack)->next->num 
        && (*stack)->next->num < (*stack)->next->next->num
        && (*stack)->num > (*stack)->next->next->num)
    {
        ra(stack);
    }
    // 1 3 2
    if ((*stack)->num < (*stack)->next->num 
        && (*stack)->next->num > (*stack)->next->next->num
        && (*stack)->num < (*stack)->next->next->num)
    {
        sa(stack);
        ra(stack);
    }
    // 2 3 1
    if ((*stack)->num < (*stack)->next->num 
        && (*stack)->next->num > (*stack)->next->next->num
        && (*stack)->num > (*stack)->next->next->num)
    {
        rra(stack);
    }
    return (0);

}

void    sort_four_values(t_stack *stacks[2])
{
    // swap 2 first values from A to B
    pb(&stacks[A], &stacks[B]);
    // sort 3 remaining values
    sort_three_values(&stacks[A]);
    // retrieve stack B value
    pa(&stacks[B], &stacks[A]);
    // and sort last value in A

}

// void    sort_five_values(t_stack *stacks[2])
// {
//         // swap 2 first values from A to B
//     pb(&stacks[A], &stacks[B]);
//     pb(&stacks[A], &stacks[B]);
//     // sort 3 remaining values
//     sort_three_values(&stacks[A]);
//     // retrieve stack B value
//     pa(&stacks[B], &stacks[A]);
//     // and sort last value in A

//     //
//     pa(&stacks[B], &stacks[A]);
//     //
// }

void    small_sort(t_stack *stacks[2], int ac)
{
    if (ac == 2)
        sort_two_values(&stacks[A]);
    if (ac == 3)
        sort_three_values(&stacks[A]);
    if (ac == 4)
        sort_four_values(stacks);
    // if (ac == 5)
        // sort_five_values(stacks);
}