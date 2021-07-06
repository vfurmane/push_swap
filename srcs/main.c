/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:41:58 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/06 10:44:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int32_t		first_number;
	t_stack_elm	*stack_b;

	stack_b = NULL;
	print_stack(stack_a);
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
	print_stack(stack_a);
	print_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_elm	*stack_a;

	if (argc <= 1)
		return (0);
	stack_a = parse_arguments(argc - 1, &argv[1]);
	if (stack_a == NULL)
		return (1);
	sort_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
