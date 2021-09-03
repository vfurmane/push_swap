/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 10:52:33 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/03 12:01:46 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_aligned_to_push(t_stack_elm *stack, uint16_t target_index,
	t_stack_elm *last_elm)
{
	return ((stack->index > target_index
			&& (last_elm->index < target_index
				|| stack->index < last_elm->index))
		|| (stack->index < target_index && stack->index < last_elm->index
			&& last_elm->index < target_index));
}

bool	should_rotate(t_stack_elm *stack, uint16_t target_index)
{
	uint16_t	price;
	uint16_t	len;

	price = 0;
	while (stack->index != target_index)
	{
		stack = stack->next;
		price++;
	}
	len = price + 1;
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (price * 2 < len);
}

void	align_a_for_target(t_stack_elm **stack_a, t_stack_elm **stack_b,
	uint16_t target_index, t_var *var)
{
	if (var->should_rotate_a)
	{
		while ((*stack_a)->index != var->stack_a_target_index)
		{
			if ((*stack_b)->index != target_index && var->should_rotate_b)
				perform_rr(stack_a, stack_b);
			else
				perform_ra(stack_a);
		}
	}
	else
	{
		while ((*stack_a)->index != var->stack_a_target_index)
		{
			if ((*stack_b)->index != target_index && var->should_rotate_b)
				perform_rrr(stack_a, stack_b);
			else
				perform_rra(stack_a);
		}
	}
}

void	align_with_target_index(t_stack_elm **stack_a, t_stack_elm **stack_b,
	uint16_t target_index)
{
	t_var		var;
	t_stack_elm	*last_elm;
	t_stack_elm	*stack_a_copy;

	last_elm = ft_lstlast(stack_a);
	stack_a_copy = *stack_a;
	while (!is_aligned_to_push(*stack_a, target_index, last_elm))
	{
		if (last_elm->next == NULL)
			last_elm = *stack_a;
		else
			last_elm = last_elm->next;
		*stack_a = (*stack_a)->next;
	}
	var.stack_a_target_index = (*stack_a)->index;
	*stack_a = stack_a_copy;
	var.should_rotate_a = should_rotate(*stack_a, var.stack_a_target_index);
	var.should_rotate_b = should_rotate(*stack_b, target_index);
	align_a_for_target(stack_a, stack_b, target_index, &var);
	while ((*stack_b)->index != target_index)
		if (var.should_rotate_b)
			perform_rb(stack_b);
	else
		perform_rrb(stack_b);
}
