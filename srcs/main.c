/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:41:58 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/29 11:44:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_elm	*stack_a;

	if (argc <= 1)
		return (0);
	stack_a = parse_arguments(argc - 1, &argv[1]);
	if (stack_a == NULL)
		return (1);
	print_stack(stack_a, argc - 1); /* ===== DELETE ===== */
	free(stack_a);
	return (0);
}
