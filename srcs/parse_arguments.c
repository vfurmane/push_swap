/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 23:05:31 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/25 23:05:38 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	*parse_arguments(int argc, char **argv)
{
	int		i;
	int32_t	*stack;

	stack = malloc((argc - 1) * sizeof(*stack));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}
