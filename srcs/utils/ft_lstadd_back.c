/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 08:09:51 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/04 18:27:49 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(void *lst, void *new)
{
	if (*(t_next **)lst == NULL)
		*(t_next **)lst = new;
	else
		((t_next*)ft_lstlast(*(t_next **)lst))->next = new;
}
