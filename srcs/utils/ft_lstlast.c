/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:24:17 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/04 18:25:24 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_lstlast(void *lst)
{
	if ((t_next*)lst == NULL)
		return (NULL);
	while (((t_next*)lst)->next != NULL)
		lst = ((t_next*)lst)->next;
	return (lst);
}
