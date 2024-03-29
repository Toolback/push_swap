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
    // and sort last value in A
    // if B1 > A1 && B1 < A1 
    if (stacks[B]->num > stacks[A]->num && stacks[B]->num < stacks[A]->next->num)
        {
            pa(&stacks[A], &stacks[B]);
            sa(&stacks[A]);
        }
    else if (stacks[B]->num > stacks[A]->next->num && stacks[B]->num < stacks[A]->next->next->num)
    {
        rra(&stacks[A]);
        pa(&stacks[A], &stacks[B]);
        rb(&stacks[A]);
        rb(&stacks[A]);
    }
    else if (stacks[B]->num > stacks[A]->next->next->num)
    {
        pa(&stacks[A], &stacks[B]);
        rb(&stacks[A]);
    }
    else 
    {
        pa(&stacks[A], &stacks[B]);
    }

}

void    sort_five_values(t_stack *stacks[2])
{
    int index;
    t_stack *min;
    // retrieve min value of stack A
    min = get_min_value(stacks[A]);
    printf("min value retrieved [%d]\n", min->num);
    // if necessary swap min A index 0
    index = min->get_prev_count(min);
    // printf("Index Retrieved [%d]\n", stacks[A]->get_prev_count(stacks[A]));
    if (index == 1)
        sa(&stacks[A]);
    if (index == 2)
    {
        ra(&stacks[A]);
        sa(&stacks[A]);
    }
    if (index == 3)
    {
        rra(&stacks[A]);
        rra(&stacks[A]);
    }
    if (index == 4)
        rra(&stacks[A]);
    // swap min value from A to B
    pb(&stacks[A], &stacks[B]);
    // sort 3 remaining values
    sort_four_values(&stacks[A]);
    // retrieve stack B value ->> min A value
    pa(&stacks[A], &stacks[B]);
}

void    small_sort(t_stack *stacks[2], int ac)
{
    if (ac == 2)
        sort_two_values(&stacks[A]);
    if (ac == 3)
        sort_three_values(&stacks[A]);
    if (ac == 4)
        sort_four_values(stacks);
    if (ac == 5)
        sort_five_values(stacks);
}