/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:42:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/30 13:43:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "tools.h"
# include "utils.h"

typedef struct s_stack_elm
{
	struct s_stack_elm	*next;
	int32_t				value;
	uint16_t			index;
	bool				keep_in_stack;
}						t_stack_elm;

bool		is_stack_asc_sorted(t_stack_elm *stack);
t_stack_elm	*parse_arguments(int len, char **args);

void		perform_pa(t_stack_elm **stack_b, t_stack_elm **stack_a);
void		perform_pb(t_stack_elm **stack_a, t_stack_elm **stack_b);

void		perform_ra(t_stack_elm **stack_a);
void		perform_rra(t_stack_elm **stack_a);
void		perform_rb(t_stack_elm **stack_b);
void		perform_rrb(t_stack_elm **stack_b);
void		perform_rr(t_stack_elm **stack_a, t_stack_elm **stack_b);
void		perform_rrr(t_stack_elm **stack_a, t_stack_elm **stack_b);

void		perform_sa(t_stack_elm **stack_a);

t_stack_elm	*ft_lstnew_stack_elm(void);
void		free_stack(t_stack_elm *stack);

#endif
