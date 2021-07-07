/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:41:58 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/07 16:11:38 by vfurmane         ###   ########.fr       */
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

void	perform_ra(t_stack_elm **stack_a)
{
	t_stack_elm	*elm;

	write(1, "ra\n", 3);
	elm = *stack_a;
	ft_lstadd_back(stack_a, elm);
	*stack_a = (*stack_a)->next;
	elm->next = NULL;
}

void	sort_stack(t_stack_elm *stack_a)
{
	uint16_t	i;
	int32_t		first_number;
	t_stack_elm	*stack_b;

	stack_b = NULL;
	first_number = stack_a->value;
	while (1)
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
		// perform rr
		while (is_stack_asc_sorted(stack_a) == false)
			perform_ra(&stack_a); // perform_rra
		while (stack_a->index < stack_b->index)
			perform_ra(&stack_a); // perform_rra
		perform_pa(&stack_b, &stack_a);
	}
	free_stack(stack_b);
	while (is_stack_asc_sorted(stack_a) == false)
		perform_ra(&stack_a); // perform_rra
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
