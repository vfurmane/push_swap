/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:29:08 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/05 10:24:11 by vfurmane         ###   ########.fr       */
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
