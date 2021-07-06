/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:13:12 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/04 21:05:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_lstcpy(void *lst, size_t elm_len)
{
	void	*new_lst;
	void	*initial_lst;
	t_next	*prev_elm;

	new_lst = NULL;
	initial_lst = NULL;
	prev_elm = NULL;
	while (lst != NULL)
	{
		new_lst = ft_memdup(lst, elm_len);
		if (prev_elm == NULL)
			initial_lst = new_lst;
		else
			prev_elm->next = new_lst;
		prev_elm = new_lst;
		lst = ((t_next*)lst)->next;
		
	}
	return (initial_lst);
}
