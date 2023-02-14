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
	char 	**values;

	if (ac > 1)
	{
		if (ac == 2)
		{
			values = ft_split(av[1], ' ');
			ac = ft_strarrlen(values);
		}
		else
		{
			values = av + 1;
			// ac = ft_strarrlen(values);
			ac = ac - 1;
		}
		if (has_duplicates(ac, values) == -1)
			error_exit("Error : Has at least twice same number\n");
		else
		{
			parse_stack_A(&stacks[A], ac, values);
			stacks[B] = NULL;

			printf("RETURNED AC [%d]", ac);
			if (ac <= 5)
			{
				small_sort(stacks, ac);
			}
			if (ac > 5)
			{

			}
			// sa(&stacks[A]);
			// pb(&stacks[A], &stacks[B]);
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
