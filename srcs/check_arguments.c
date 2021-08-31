/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane </var/spool/mail/vfurmane>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:16:09 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/31 20:16:16 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_arg(char *arg, t_stack_elm *stack)
{
	int		i;
	long	nbr;

	i = 0;
	if (!ft_isdigit(arg[i]) && arg[i] != '-')
		return (false);
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (false);
	nbr = ft_atol(arg);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (false);
	while (stack)
	{
		if (stack->value == nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
