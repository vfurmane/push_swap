/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:41:58 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/01 10:58:50 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_asc_sort(t_stack_elm **stack)
{
	t_stack_elm	*save_stack;
	uint16_t	price;
	int32_t		last_number;

	save_stack = *stack;
	price = 0;
	last_number = (*stack)->value;
	while (*stack != NULL && (*stack)->value >= last_number)
	{
		*stack = (*stack)->next;
		price++;
	}
	*stack = save_stack;
	if (price < ft_lstsize(stack) - price - 1)
		while (price-- > 0)
			perform_ra(stack);
	else
	{
		price = ft_lstsize(stack) - price - 1;
		while (price-- > 0)
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

int32_t	least_operations_move(t_stack_elm *stack_a, t_stack_elm *stack_b,
	uint16_t base_move, uint16_t best_price)
{
	uint16_t	price;
	t_stack_elm	*best_elm;
	t_stack_elm	*stack_a_copy;

	best_elm = NULL;
	stack_a_copy = stack_a;
	while (stack_b != NULL)
	{
		price = base_move;
		while (is_not_aligned_to_push(stack_a, stack_b->index))
		{
			stack_a = stack_a->next;
			price++;
		}
		if (base_move * 2 >= ft_lstsize(stack_b) + base_move)
			price = price - base_move + ft_lstsize(stack_b);
		if (price < best_price)
			best_elm = stack_b;
		best_price = best_price - best_price * (price < best_price)
			+ price * (price < best_price);
		base_move++;
		stack_a = stack_a_copy;
		stack_b = stack_b->next;
	}
	return (best_elm->index);
}

void	sort_stack(t_stack_elm *stack_a)
{
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
	while (stack_b != NULL)
	{
		target_index = least_operations_move(stack_a, stack_b, 0, -1);
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
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
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
