/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:48:26 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/30 13:43:20 by vfurmane         ###   ########.fr       */
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

void	perform_rra(t_stack_elm **stack_a)
{
	t_stack_elm	*elm;
	t_stack_elm	*stack_cpy;

	write(1, "rra\n", 4);
	elm = ft_lstlast(*stack_a);
	ft_lstadd_front(stack_a, elm);
	stack_cpy = *stack_a;
	while (stack_cpy && stack_cpy->next != elm)
		stack_cpy = stack_cpy->next;
	stack_cpy->next = NULL;
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

void	perform_rrb(t_stack_elm **stack_b)
{
	t_stack_elm	*elm;
	t_stack_elm	*stack_cpy;

	write(1, "rrb\n", 4);
	elm = ft_lstlast(*stack_b);
	ft_lstadd_front(stack_b, elm);
	stack_cpy = *stack_b;
	while (stack_cpy && stack_cpy->next != elm)
		stack_cpy = stack_cpy->next;
	stack_cpy->next = NULL;
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

void	perform_rrr(t_stack_elm **stack_a, t_stack_elm **stack_b)
{
	t_stack_elm	*elm;
	t_stack_elm	*stack_cpy;

	write(1, "rrr\n", 4);
	elm = ft_lstlast(*stack_a);
	ft_lstadd_front(stack_a, elm);
	stack_cpy = *stack_a;
	while (stack_cpy && stack_cpy->next != elm)
		stack_cpy = stack_cpy->next;
	stack_cpy->next = NULL;
	elm = ft_lstlast(*stack_b);
	ft_lstadd_front(stack_b, elm);
	stack_cpy = *stack_b;
	while (stack_cpy && stack_cpy->next != elm)
		stack_cpy = stack_cpy->next;
	stack_cpy->next = NULL;
}
