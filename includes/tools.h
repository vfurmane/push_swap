/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:33:20 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/30 10:57:30 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include "push_swap.h"

typedef struct s_stack_elm	t_stack_elm;

void	print_stack(t_stack_elm *stack);
void	print_stacks(t_stack_elm *stack_a, t_stack_elm *stack_b);

#endif
