/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:33:20 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/28 14:41:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_stack_elm
{
	int32_t		value;
	uint16_t	index;
	bool		keep_in_stack;
}				t_stack_elm;

void	print_stack(t_stack_elm *stack, int len);

#endif
