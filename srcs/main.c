/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:41:58 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/08 11:06:41 by vfurmane         ###   ########.fr       */
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
		while ((((t_stack_elm*)ft_lstlast(stack_a))->value > stack_b->value && ((t_stack_elm*)ft_lstlast(stack_a))->value < stack_a->value) || stack_a->value < stack_b->value)
			perform_rra(&stack_a); // perform_rra
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
