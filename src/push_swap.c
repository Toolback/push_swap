/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:33:20 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/11 16:33:56 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stacks[2];

	if (ac > 1)
	{
		parse_stack_A(&stacks[A], ac, av);
		stacks[B] = NULL;
		t_stack *node_1 = stacks[A]->next;
		t_stack *node_2 = node_1->next;
		t_stack *node_3 = node_2->next;
				printf("returned node  0 : %d\n", (stacks[A])->num);
		printf("returned node  1 : %d\n", node_1->num);
		printf("returned node  2  : %d\n", node_2->num);
		printf("returned node  3  : %d\n\n", node_3->num);
		// sa(&stacks[A]);
		rb(&stacks[A]);
		node_1 = stacks[A]->next;
		node_2 = node_1->next;
		node_3 = node_2->next;
		printf("returned node  0 : %d\n", (stacks[A])->num);
		printf("returned node  1 : %d\n", node_1->num);
		printf("returned node  2  : %d\n", node_2->num);
		printf("returned node  3  : %d\n\n", node_3->num);
		print_res(stacks);
	}
	else
	{
		error_exit("Invalid Args Format, should be -> [./pushswap 1 3 2 4 6]");
	}
	return (0);
}
