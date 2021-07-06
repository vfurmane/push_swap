/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:00:25 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/06 10:19:46 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_front(void *lst, void *new)
{
	((t_next*)new)->next = *(t_next**)lst;
	*(t_next**)lst = new;
}
