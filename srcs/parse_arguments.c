/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 23:05:31 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/29 16:54:21 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_stack_asc_sorted(t_stack_elm *stack, int len)
{
	uint16_t	i;
	int32_t		last_nbr;

	last_nbr = INT_MIN;
	i = 0;
	while (i < len)
	{
		if (stack[i].value < last_nbr)
			return (0);
		last_nbr = stack[i].value;
		i++;
	}
	return (1);
}

static void	set_stack_index(t_stack_elm *stack, t_stack_elm *new_stack, int len)
{
	uint16_t	i;
	uint16_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack[i].value == new_stack[j].value)
				stack[i].index = j;
			j++;
		}
		i++;
	}
}

static void	keep_in_stack(t_stack_elm *stack, int len)
{
	uint16_t	i;
	int32_t		last_nbr;

	last_nbr = INT_MIN;
	i = 0;
	while (i < len)
	{
		if (stack[i].value > last_nbr)
		{
			stack[i].keep_in_stack = 1;
			last_nbr = stack[i].value;
		}
		else
			stack[i].keep_in_stack = 0;
		i++;
	}
}

static int	pre_sort_stack(t_stack_elm *stack, int len)
{
	uint16_t	i;
	t_stack_elm	*new_stack;

	new_stack = ft_memdup(stack, len * sizeof(*stack));
	if (new_stack == NULL)
		return (-1);
	while (!is_stack_asc_sorted(new_stack, len))
	{
		i = 0;
		while (i < len - 1)
		{
			if (new_stack[i].value > new_stack[i + 1].value)
			{
				ft_swap4(&new_stack[i].value, &new_stack[i + 1].value);
			}
			i++;
		}
	}
	set_stack_index(stack, new_stack, len);
	keep_in_stack(stack, len);
	free(new_stack);
	return (1);
}

t_stack_elm	*parse_arguments(int len, char **args)
{
	int		i;
	t_stack_elm	*stack;

	stack = malloc(len * sizeof(*stack));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		stack[i].value = ft_atoi(args[i]);
		stack[i].index = i;
		i++;
	}
	if (pre_sort_stack(stack, len) < 1)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}
