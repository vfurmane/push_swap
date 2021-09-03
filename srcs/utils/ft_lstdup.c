/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:21:50 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/03 13:47:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_lstdup(void *lst)
{
	void	*new_lst;

	new_lst = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(new_lst, lst);
		lst = ((t_next *)lst)->next;
	}
	return (new_lst);
}
