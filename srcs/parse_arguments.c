/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 23:05:31 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/06 16:10:47 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_asc_sorted(t_stack_elm *stack)
{
	int32_t		last_nbr;

	last_nbr = INT_MIN;
	while (stack != NULL)
	{
		if (stack->value < last_nbr)
			return (0);
		last_nbr = stack->value;
		stack = stack->next;
	}
	return (1);
}

static void	set_stack_index(t_stack_elm *stack, t_stack_elm *new_stack)
{
	t_stack_elm	*iter_stack;
	uint16_t	i;

	while (stack != NULL)
	{
		i = 0;
		iter_stack = new_stack;
		while (iter_stack != NULL)
		{
			if (stack->value == iter_stack->value)
			{
				stack->index = i;
				break ;
			}
			i++;
			iter_stack = iter_stack->next;
		}
		stack = stack->next;
	}
}

static void	keep_in_stack(t_stack_elm *stack)
{
	int32_t		last_nbr;

	last_nbr = INT_MIN;
	while (stack != NULL)
	{
		if (stack->value > last_nbr)
		{
			stack->keep_in_stack = 1;
			last_nbr = stack->value;
		}
		else
			stack->keep_in_stack = 0;
		stack = stack->next;
	}
}

static int	pre_sort_stack(t_stack_elm *stack)
{
	t_stack_elm	*initial_stack;
	t_stack_elm	*new_stack;

	new_stack = ft_lstcpy(stack, sizeof (*new_stack));
	if (new_stack == NULL)
		return (-1);
	initial_stack = new_stack;
	while (is_stack_asc_sorted(new_stack) == false)
	{
		while (new_stack->next != NULL)
		{
			if (new_stack->value > new_stack->next->value)
				ft_swap4(&new_stack->value, &new_stack->next->value);
			new_stack = new_stack->next;
		}
		new_stack = initial_stack;
	}
	new_stack = initial_stack;
	set_stack_index(stack, new_stack);
	keep_in_stack(stack);
	free_stack(new_stack);
	return (1);
}

t_stack_elm	*parse_arguments(int len, char **args)
{
	int		i;
	t_stack_elm	*stack;
	t_stack_elm	*elm;

	stack = NULL;
	i = 0;
	while (i < len)
	{
		elm = ft_lstnew_stack_elm();
		ft_lstadd_back(&stack, elm);
		elm->value = ft_atoi(args[i]);
		elm->index = i;
		i++;
	}
	if (pre_sort_stack(stack) < 1)
	{
		free_stack(stack);
		return (NULL);
	}
	return (stack);
}
