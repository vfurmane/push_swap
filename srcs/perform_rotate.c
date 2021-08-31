/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:48:26 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/31 16:22:10 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_ra(t_stack_elm **stack_a)
{
	t_stack_elm	*elm;

	write(1, "ra\n", 3);
	elm = *stack_a;
	ft_lstadd_back(stack_a, elm);
	*stack_a = (*stack_a)->next;
	elm->next = NULL;
}

void	perform_rb(t_stack_elm **stack_b)
{
	t_stack_elm	*elm;

	write(1, "rb\n", 3);
	elm = *stack_b;
	ft_lstadd_back(stack_b, elm);
	*stack_b = (*stack_b)->next;
	elm->next = NULL;
}

void	perform_rr(t_stack_elm **stack_a, t_stack_elm **stack_b)
{
	t_stack_elm	*elm;

	write(1, "rr\n", 3);
	elm = *stack_a;
	ft_lstadd_back(stack_a, elm);
	*stack_a = (*stack_a)->next;
	elm->next = NULL;
	elm = *stack_b;
	ft_lstadd_back(stack_b, elm);
	*stack_b = (*stack_b)->next;
	elm->next = NULL;
}
