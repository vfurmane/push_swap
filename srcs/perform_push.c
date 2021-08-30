/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:45:34 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/30 10:45:49 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_pa(t_stack_elm **stack_b, t_stack_elm **stack_a)
{
	t_stack_elm	*elm_copy;
	t_stack_elm	*next_elm;

	write(1, "pa\n", 3);
	elm_copy = ft_memdup(*stack_b, sizeof (**stack_b));
	ft_lstadd_front(stack_a, elm_copy);
	next_elm = (*stack_b)->next;
	free(*stack_b);
	*stack_b = next_elm;
}

void	perform_pb(t_stack_elm **stack_a, t_stack_elm **stack_b)
{
	t_stack_elm	*elm_copy;
	t_stack_elm	*next_elm;

	write(1, "pb\n", 3);
	elm_copy = ft_memdup(*stack_a, sizeof (**stack_a));
	ft_lstadd_front(stack_b, elm_copy);
	next_elm = (*stack_a)->next;
	free(*stack_a);
	*stack_a = next_elm;
}
