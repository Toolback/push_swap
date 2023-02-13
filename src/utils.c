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
	t_stack *temp;
	if (!head)
	{
		ft_printf("get_last_node: head is null\n");
		// exit(EXIT_FAILURE);
		return (NULL);
	}
	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

// void	init_stacks(t_stack *stacks[2], int ac, char **av)
// {
// 	int i;

// 	i = 2;
// 	stacks[A] = (t_stack *)malloc(sizeof(t_stack));
// 	stacks[B] = (t_stack *)malloc(sizeof(t_stack));
// 		printf("LAST NODE NUM : %d\n", stacks[A]->num);

// 	if (stacks[A] == NULL || stacks[B] == NULL)
// 		error_exit("Malloc failed");
// 	stacks[A]->prev = NULL;
// 	stacks[A]->num = ft_atoi(av[1]);
// 	stacks[A]->next = NULL;
// 	stacks[B]->prev = NULL;
// 	// stacks[B]->num = NULL;
// 	stacks[B]->next = NULL;
// 	while (ac >= i)
// 	{
// 		new_node(get_last_node(stacks[A]), ft_atoi(av[i++]));
// 	}
// }

void	parse_stack_A(t_stack **stack, int ac, char **av)
{
	int i;
	t_stack *last;
	i = 2;
	// create first node
	*stack = add_value_back(*stack, ft_atoi(av[1]));
	last = *stack;
	// create as many node as args
	while (ac > i)
	{
		last = add_value_back(last, ft_atoi(av[i++]));
		// printf("LAST NODE NUM : %d\n", last->num);
	}
}

t_stack *add_value_back(t_stack *node, int value)
{

	// if no node, create the first of the list
	if (!node)
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		if (node == NULL)
			error_exit("Malloc failed");
		(node)->prev = NULL;
		(node)->num = value;
		(node)->next = NULL;
		return (node);
	}
	// else add value at last node
	else 
	{
		(node)->next = (t_stack *)malloc(sizeof(t_stack));
		if ((node)->next == NULL)
			error_exit("Malloc failed");
		(node)->next->prev = node;
		(node)->next->num = value;
		(node)->next->next = NULL;
		return ((node)->next);
	}
}

// void	new_node(t_stack *last_node, int value)
// {
// 	t_stack	*new_node;

// 	new_node = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new_node)
// 		exit(EXIT_FAILURE);
// 	last_node->next = new_node;
// 	new_node->prev = last_node;
// 	new_node->next = NULL;
// 	new_node->num = value;
// }

int	lst_size(t_stack *stack)
{
	int	num;

	num = 0;
	if (stack == NULL)
	{
		ft_printf("No Found\n");
		return (num);	
	}

	ft_printf("euuh Found\n");
	t_stack	*save = stack;
	while (save)
	{
		num++;
	ft_printf("Found What [%d] ? : [%d]\n",num, save->num);
		save = save->next;
	}
	// num--;
	// stack = save;


	return (num);
}

// TODO /!

int has_duplicates(int argc, char *argv[]) {
    int i, j;
    int *values = (int*) ft_calloc(argc - 1, sizeof(int));
    for (i = 1; i < argc; i++) {
        values[i - 1] = ft_atoi(argv[i]);
        for (j = 0; j < i - 1; j++) {
            if (values[j] == values[i - 1]) {
                free(values);
                return -1;
            }
        }
    }
    free(values);
    return 0;
}


void	print_res(t_stack *stacks[2])
{
	int	sizeA = lst_size(stacks[A]);
	ft_printf("Elements in Stacks A : [%d]\n", sizeA);
	int	sizeB = lst_size(stacks[B]);
	ft_printf("Elements in Stacks B : [%d]\n", sizeB);
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

// Fonction pour afficher une erreur et quitter le programme
void error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
