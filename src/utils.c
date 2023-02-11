/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:33:25 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/10 17:46:50 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_stack	*get_last_node(t_stack *head)
{
	if (!head)
	{
		ft_printf("get_last_node: head is null\n");
		exit(EXIT_FAILURE);
	}
	while (head->next)
		head = head->next;
	return (head);
}

void	init_stacks(t_stack *stacks[2], int ac, char **av)
{
	int i;

	i = 2;
	stacks[A] = (t_stack *)malloc(sizeof(t_stack));
	stacks[B] = (t_stack *)malloc(sizeof(t_stack));
	if (stacks[A] == NULL || stacks[B] == NULL)
		error_exit("Malloc failed");
	stacks[A]->prev = NULL;
	stacks[A]->num = ft_atoi(av[1]);
	stacks[A]->next = NULL;
	stacks[B]->prev = NULL;
	// stacks[B]->num = NULL;
	stacks[B]->next = NULL;
	while (ac >= i)
	{
		new_node(get_last_node(stacks[A]), ft_atoi(av[i++]));
	}
}

void	new_node(t_stack *last_node, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit(EXIT_FAILURE);
	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->num = value;
	new_node->next = NULL;
}

void	print_res(t_stack *stacks[2])
{
	int	sizeA = lst_size(stacks[A]) - 1;
	int	sizeB = lst_size(stacks[B]) - 1;
	int	size;
	int	i;

	i = 0;
	size = sizeA > sizeB ? sizeA : sizeB;
	ft_printf("Returned Stacks :\n");
	ft_printf("------------------\n");
	while (i < size)
	{
		if (i < sizeA)
		{
			ft_printf("%d ", stacks[A]->num);
			stacks[A] = stacks[A]->next;
		}
		else
			ft_printf("  ");
		if (i < sizeB)
		{
			ft_printf("%d\n", stacks[B]->num);
			stacks[B] = stacks[B]->next;
		}
		else
			printf("\n");
		i++;
	}
	ft_printf("------------------\n");
}

int	lst_size(t_stack *stack)
{
	int	num;
	//t_stack	*save = stack;

	num = 0;
	while (stack)
	{
		num++;
		stack = stack->next;
	}
	//stack = save;


	return (num);
}

// Fonction pour afficher une erreur et quitter le programme
void error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
