/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:28:22 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/28 15:07:14 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_memswap(void *ptr1, void *ptr2, size_t len)
{
	void	*tmp;

	tmp = malloc(len);
	if (tmp == NULL)
		return ;
	ft_memmove(tmp, ptr1, len);
	ft_memmove(ptr1, ptr2, len);
	ft_memmove(ptr2, tmp, len);
	free(tmp);
}
