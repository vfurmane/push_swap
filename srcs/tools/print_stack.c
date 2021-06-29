/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:29:08 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/28 19:25:01 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	print_stack(t_stack_elm *stack, int len)
{
	static int	counter;
	int			i;

	printf("CALL NO %d\n\n", ++counter);
	i = 0;
	while (i < len)
	{
		printf("[%05d] | %d (%d)\n", i + 1, stack[i].value, stack[i].index);
		i++;
	}
	printf("\n");
}
