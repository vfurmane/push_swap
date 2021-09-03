/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_elm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 06:02:18 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/03 13:42:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elm	*ft_lstnew_stack_elm(void)
{
	t_stack_elm	*elm;

	elm = malloc(sizeof (*elm));
	if (elm == NULL)
		return (elm);
	elm->next = NULL;
	return (elm);
}

int	free_stack(t_stack_elm *stack)
{
	t_stack_elm	*initial_stack;
	t_stack_elm	*next_elm;

	initial_stack = stack;
	while (stack != NULL)
	{
		next_elm = stack->next;
		free(stack);
		stack = next_elm;
	}
	return (0);
}
