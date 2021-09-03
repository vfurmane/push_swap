/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hardcoded.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:37:32 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/03 13:41:59 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_numbers(t_stack_elm **stack, bool free)
{
	while (!is_stack_asc_sorted(*stack))
	{
		if ((*stack)->index - 1 == (*stack)->next->index
			|| ((*stack)->index == 0 && (*stack)->next->index == 2))
			perform_sa(stack);
		else if ((*stack)->index == 2 && (*stack)->next->index == 0)
			perform_ra(stack);
		else if ((*stack)->index == 1 && (*stack)->next->index == 2)
			perform_rra(stack);
	}
	if (free)
		free_stack(*stack);
	return (0);
}

static void	save_index(t_stack_elm *stack)
{
	while (stack != NULL)
	{
		stack->index_for_five = stack->index;
		stack = stack->next;
	}
}

static void	restore_index(t_stack_elm *stack)
{
	while (stack != NULL)
	{
		stack->index = stack->index_for_five;
		stack = stack->next;
	}
}

int	sort_five_numbers(t_stack_elm *stack_a)
{
	int32_t		target_index;
	t_stack_elm	*stack_b;

	if (is_stack_asc_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	stack_b = NULL;
	perform_pb(&stack_a, &stack_b);
	perform_pb(&stack_a, &stack_b);
	save_index(stack_a);
	pre_sort_stack(stack_a);
	sort_three_numbers(&stack_a, 0);
	restore_index(stack_a);
	while (stack_b != NULL)
	{
		target_index = least_operations_move(stack_a, stack_b, 0, -1);
		align_with_target_index(&stack_a, &stack_b, target_index);
		perform_pa(&stack_b, &stack_a);
	}
	if (!is_stack_asc_sorted(stack_a))
		simple_asc_sort(&stack_a);
	free_stack(stack_a);
	return (free_stack(stack_b));
}
