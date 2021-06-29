/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:54:08 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/29 10:57:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memdup(const void *ptr, size_t len)
{
	char	*new_ptr;

	new_ptr = malloc(len * sizeof(*new_ptr));
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = ft_memmove(new_ptr, ptr, len);
	return (new_ptr);
}
