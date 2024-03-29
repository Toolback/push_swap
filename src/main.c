/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:10:49 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/20 21:10:49 by jurenaul         ###   ########.fr       */
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
			ac = ac - 1;
		}
		if (has_duplicates(ac, values) == -1)
			error_exit("Error : Has at least twice same number\n");
		else
		{
			parse_stack_A(&stacks[A], ac, values);
			// printf("returned PREV [%d]", stacks[A]->next->get_prev_count(stacks[A]->next));

			stacks[B] = NULL;
			if (ac <= 5)
				small_sort(stacks, ac);
			if (ac > 5)
			{
				big_sort(stacks, ac);
			}
			print_res(stacks);
			return (0);
		}
	}
	else
	{
		error_exit("Invalid Args Format, should be -> [./pushswap 1 3 2 4 6]");
	}
	return (0);
}
