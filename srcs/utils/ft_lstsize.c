/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:03:45 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/30 10:56:40 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_lstsize(void *lst)
{
	int	len;

	if (lst == NULL)
		return (0);
	len = 1;
	lst = ((t_next *)lst)->next;
	while (lst)
	{
		lst = ((t_next *)lst)->next;
		len++;
	}
	return (len);
}
