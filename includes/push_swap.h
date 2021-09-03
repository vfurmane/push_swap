/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:42:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/03 14:50:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"

typedef struct s_stack_elm
{
	struct s_stack_elm	*next;
	int32_t				value;
	uint16_t			index;
	uint16_t			index_for_five;
	bool				keep_in_stack;
}						t_stack_elm;

typedef struct s_var
{
	uint16_t	stack_a_target_index;
	bool		should_rotate_a;
	bool		should_rotate_b;
}						t_var;

bool		is_aligned_to_push(t_stack_elm *stack, uint16_t target_index,
				t_stack_elm *last_elm);
void		align_with_target_index(t_stack_elm **stack_a,
				t_stack_elm **stack_b, uint16_t target_index);

bool		check_arg(char *arg, t_stack_elm *stack);

bool		is_stack_asc_sorted(t_stack_elm *stack);
int			pre_sort_stack(t_stack_elm *stack);
t_stack_elm	*parse_arguments(int len, char **args);

void		perform_pa(t_stack_elm **stack_b, t_stack_elm **stack_a);
void		perform_pb(t_stack_elm **stack_a, t_stack_elm **stack_b);

void		perform_rra(t_stack_elm **stack_a);
void		perform_rrb(t_stack_elm **stack_b);
void		perform_rrr(t_stack_elm **stack_a, t_stack_elm **stack_b);

void		perform_ra(t_stack_elm **stack_a);
void		perform_rb(t_stack_elm **stack_b);
void		perform_rr(t_stack_elm **stack_a, t_stack_elm **stack_b);

void		perform_sa(t_stack_elm **stack_a);

int			sort_three_numbers(t_stack_elm **stack, bool free);
int			sort_five_numbers(t_stack_elm *stack_a);

void		simple_asc_sort(t_stack_elm **stack);
bool		need_to_push_b(t_stack_elm *stack_a);
int32_t		least_operations_move(t_stack_elm *stack_a, t_stack_elm *stack_b,
				uint16_t base_move, uint16_t best_price);
void		small_operations(t_stack_elm **stack_a, t_stack_elm **stack_b);

t_stack_elm	*ft_lstnew_stack_elm(void);
int			free_stack(t_stack_elm *stack);

#endif
