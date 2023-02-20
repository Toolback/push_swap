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

t_stack	*get_last_node(t_stack *tail)
{
	t_stack *temp;
	if (!tail)
	{
		ft_printf("get_last_node: tail is null\n");
		// exit(EXIT_FAILURE);
		return (NULL);
	}
	temp = tail;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_stack *get_min_value(t_stack *tail)
{
	t_stack *save = tail;
	t_stack *min;
	while (save)
	{
		if (min->num > save->num)
			min = save;
		save = save->next;
	}
	return (min);
}

void	parse_stack_A(t_stack **stack, int ac, char **av)
{
	int i;
	t_stack *last;
	i = 1;
	// create first node
	*stack = NULL;
	*stack = add_value_back(*stack, ft_atoi(av[0]));
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
		node->prev = NULL;
		node->num = value;
		node->next = NULL;
		node->get_prev_count = &get_prev_count;
		return (node);
	}
	// else add value at last node
	else 
	{
		node->next = (t_stack *)malloc(sizeof(t_stack));
		if (node->next == NULL)
			error_exit("Malloc failed");
		node->next->prev = node;
		node->next->num = value;
		node->next->next = NULL;
		node->next->get_prev_count = &get_prev_count;
		return (node->next);
	}
}

int	lst_size(t_stack *stack)
{
	int	num;

	num = 0;
	if (stack == NULL)
	{
		// ft_printf("No Found\n");
		return (num);	
	}

	t_stack	*save = stack;
	while (save)
	{
		num++;
	// ft_printf("Found What [%d] ? : [%d]\n",num, save->num);
		save = save->next;
	}
	// num--;

	return (num);
}

int get_prev_count(t_stack *stack) 
{
    int count = 0;
	if (!stack)
	{
		ft_printf("get_prev_count: stack is null\n");
		return (-1);
	}
	t_stack	*save = stack;
    while (save->prev) {
		save = save->prev;
        count++;
    }
    return count;
}

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
	// ft_printf("Elements in Stacks A : [%d]\n", sizeA);
	int	sizeB = lst_size(stacks[B]);
	// ft_printf("Elements in Stacks B : [%d]\n", sizeB);
	int	size;
	int	i;
	int flag;

	i = 0;
	flag = 0;
	size = sizeA > sizeB ? sizeA : sizeB;
	ft_printf("\n\nReturned Stacks :\n");
	ft_printf("---\n");
	while (i < size)
	{
		if (i < sizeA)
		{
			ft_printf("%d ", stacks[A]->num);
			if (stacks[A]->next)
			{
				if (stacks[A]->num > stacks[A]->next->num)
					flag = 1;
			}
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
	ft_printf("---\n");
	ft_printf("A B\n");
	if (flag)
	    printf("\033[31mError : Final List Not Sorted\033[0m\n");
	else
		printf("\033[32mSucces <3 Final List Sorted !\033[0m\n");

}

// Fonction pour afficher une erreur et quitter le programme
void error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
