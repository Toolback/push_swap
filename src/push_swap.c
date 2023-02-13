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
		if (has_duplicates(ac, av) == -1)
			error_exit("Error : Has at least twice same number\n");
		else
		{
			parse_stack_A(&stacks[A], ac, av);
			stacks[B] = NULL;

			// sa(&stacks[A]);
			pb(&stacks[A], &stacks[B]);
			// rb(&stacks[A]);
			
			print_res(stacks);
		}
	}
	else
	{
		error_exit("Invalid Args Format, should be -> [./pushswap 1 3 2 4 6]");
	}
	return (0);
}
