/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:27:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/30 11:40:57 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_sa(t_stack_elm **stack_a)
{
	t_stack_elm	*elm;
	t_stack_elm	*new_first_elm;

	write(1, "sa\n", 3);
	elm = (*stack_a)->next->next;
	new_first_elm = (*stack_a)->next;
	(*stack_a)->next->next = (*stack_a);
	(*stack_a)->next = elm;
	*stack_a = new_first_elm;
}
