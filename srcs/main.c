/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:41:58 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/30 10:55:22 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_for_number(t_stack_elm **stack, int32_t nbr)
{
	t_stack_elm	*save_stack;
	uint16_t	price;
	int32_t		last_number;
	uint16_t	i;

	save_stack = *stack;
	price = 0;
	last_number = ((t_stack_elm *)ft_lstlast(*stack))->value;
	i = 0;
	while (*stack != NULL && (nbr < last_number && nbr > (*stack)->next->value))
	{
		last_number = (*stack)->value;
		*stack = (*stack)->next;
		i++;
	}
	*stack = save_stack;
	if (i < ft_lstsize(*stack) / 2)
	{
		i = 0;
		while ((((t_stack_elm *)ft_lstlast(*stack))->value > nbr
				&& ((t_stack_elm *)ft_lstlast(*stack))->value < (*stack)->value)
			|| (*stack)->value < nbr)
			perform_ra(stack);
	}
	else
	{
		price = i;
		i = 0;
		while ((((t_stack_elm *)ft_lstlast(stack))->value > nbr
				&& ((t_stack_elm *)ft_lstlast(stack))->value < (*stack)->value)
			|| (*stack)->value < nbr)
			perform_rra(stack);
	}
}

void	simple_asc_sort(t_stack_elm **stack)
{
	t_stack_elm	*save_stack;
	uint16_t	price;
	int32_t		last_number;
	uint16_t	i;

	save_stack = *stack;
	price = 0;
	last_number = (*stack)->value;
	i = 0;
	while (*stack != NULL && (*stack)->value >= last_number)
	{
		*stack = (*stack)->next;
		i++;
	}
	price = i;
	i = 0;
	while (*stack != NULL)
	{
		*stack = (*stack)->next;
		i++;
	}
	*stack = save_stack;
	if (price < i)
	{
		i = 0;
		while (i++ < price)
			perform_ra(stack);
	}
	else
	{
		price = i;
		i = 0;
		while (i++ < price)
			perform_rra(stack);
	}
}

bool	need_to_push_b(t_stack_elm *stack_a)
{
	while (stack_a)
	{
		if (stack_a->keep_in_stack == false)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int32_t	least_operations_move(t_stack_elm *stack_a, t_stack_elm *stack_b)
{
	uint16_t	base_move;
	uint16_t	stack_a_len;
	uint16_t	stack_b_len;
	uint16_t	price;
	uint16_t	best_price;
	t_stack_elm	*best_elm;
	t_stack_elm	*stack_a_copy;

	best_elm = NULL;
	best_price = -1;
	base_move = 0;
	stack_a_copy = stack_a;
	stack_a_len = ft_lstsize(stack_a);
	stack_b_len = ft_lstsize(stack_b);
	while (stack_b != NULL)
	{
		stack_a = stack_a_copy;
		price = base_move;
		while ((((t_stack_elm *)ft_lstlast(stack_a))->index > stack_b->index
				&& ((t_stack_elm *)ft_lstlast(stack_a))->index < stack_a->index)
			|| stack_a->index < stack_b->index)
		{
			stack_a = stack_a->next;
			price++;
		}
		if (price < best_price)
		{
			best_price = price;
			best_elm = stack_b;
		}
		base_move++;
		stack_b = stack_b->next;
	}
	return (best_elm->index);
}

void	align_with_target_index(t_stack_elm **stack_a, t_stack_elm **stack_b,
	uint16_t target_index)
{
	while ((((t_stack_elm *)ft_lstlast(*stack_a))->index > target_index
			&& ((t_stack_elm *)ft_lstlast(*stack_a))->index < (*stack_a)->index)
		|| (*stack_a)->index < target_index)
	{
		perform_ra(stack_a);
	}
	while ((*stack_b)->index != target_index)
	{
		perform_rb(stack_b);
	}
}

void	sort_stack(t_stack_elm *stack_a)
{
	uint16_t	i;
	int32_t		first_number;
	int32_t		target_index;
	t_stack_elm	*stack_b;

	stack_b = NULL;
	first_number = stack_a->value;
	while (need_to_push_b(stack_a) && !is_stack_asc_sorted(stack_a))
	{
		if (stack_a->keep_in_stack == false)
			perform_pb(&stack_a, &stack_b);
		else
			perform_ra(&stack_a);
		if (stack_a->value == first_number)
			break ;
	}
	i = 0;
	while (stack_b != NULL)
	{
		target_index = least_operations_move(stack_a, stack_b);
		align_with_target_index(&stack_a, &stack_b, target_index);
		perform_pa(&stack_b, &stack_a);
	}
	free_stack(stack_b);
	if (!is_stack_asc_sorted(stack_a))
		simple_asc_sort(&stack_a);
	free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack_elm	*stack_a;

	if (argc <= 1)
		return (0);
	stack_a = parse_arguments(argc - 1, &argv[1]);
	if (is_stack_asc_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	if (stack_a == NULL)
		return (1);
	sort_stack(stack_a);
	return (0);
}
