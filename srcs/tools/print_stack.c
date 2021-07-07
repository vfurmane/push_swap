/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:29:08 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/07 09:41:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	print_stack(t_stack_elm *stack)
{
	static int	counter;
	int			i;

	printf("CALL NO %d\n\n", ++counter);
	i = 0;
	while (stack != NULL)
	{
		printf("[%05d] | %d (%d) %d\n", i + 1, stack->value, stack->index, stack->keep_in_stack);
		stack = stack->next;
		i++;
	}
	printf("\n");
}

void	print_stacks(t_stack_elm *stack_a, t_stack_elm *stack_b)
{
	static int	counter;
	int			i;

	printf("CALL NO %d\n\n", ++counter);
	i = 0;
	while (stack_a != NULL || stack_b != NULL)
	{
		printf("[%05d] ", i + 1);
		if (stack_a != NULL)
		{
			printf("%3d", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			printf("%3c", ' ');
		printf(" | ");
		if (stack_b != NULL)
		{
			printf("%3d", stack_b->value);
			stack_b = stack_b->next;
		}
		else
			printf("%3c", ' ');
		printf("\n");
		i++;
	}
	printf("\n");
}
