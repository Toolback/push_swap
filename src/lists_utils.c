/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:09:28 by jurenaul          #+#    #+#             */
/*   Updated: 2023/02/20 21:09:28 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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

t_stack	*get_first_node(t_stack *head)
{
	t_stack *temp;
	if (!head)
	{
		ft_printf("get_first_node: head is null\n");
		// exit(EXIT_FAILURE);
		return (NULL);
	}
	temp = head;
	while (temp->prev)
		temp = temp->prev;
	return (temp);
}

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

t_stack *copy_list(t_stack *list)
{
    t_stack *copy = NULL;
    t_stack *curr_node = NULL;
    t_stack *new_node = NULL;

    // Parcourir la liste chaînée originale
    curr_node = list;
    while (curr_node != NULL)
    {
        // Allouer un nouveau noeud et copier les valeurs
        new_node = (t_stack *)malloc(sizeof(t_stack));
        new_node->num = curr_node->num;
        new_node->next = NULL;

        // Ajouter le nouveau noeud à la copie de la liste chaînée
        if (copy == NULL)
        {
            copy = new_node;
        }
        else
        {
            // Parcourir la copie de la liste chaînée et ajouter le nouveau noeud à la fin
            t_stack *copy_node = copy;
            while (copy_node->next != NULL)
            {
                copy_node = copy_node->next;
            }
            copy_node->next = new_node;
        }

        curr_node = curr_node->next;
    }

    return copy;
}