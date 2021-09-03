/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:40:03 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/03 13:45:24 by vfurmane         ###   ########.fr       */
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

uint16_t	calculate_price(t_stack_elm *stack_a, t_stack_elm *stack_b,
	uint16_t price)
{
	t_stack_elm	*last_elm;

	last_elm = ft_lstlast(stack_a);
	while (!is_aligned_to_push(stack_a, stack_b->index, last_elm))
	{
		if (last_elm->next == NULL)
			last_elm = stack_a;
		else
			last_elm = last_elm->next;
		stack_a = stack_a->next;
		price++;
	}
	return (price);
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
		price = calculate_price(stack_a, stack_b, price);
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

void	small_operations(t_stack_elm **stack_a, t_stack_elm **stack_b)
{
	if ((*stack_a)->keep_in_stack == false)
		perform_pb(stack_a, stack_b);
	else
		perform_ra(stack_a);
}
