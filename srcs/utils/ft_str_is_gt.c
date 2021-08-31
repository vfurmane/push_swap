/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_gt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:51:04 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/31 11:59:11 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	free_int_return(void *ptr, int ret)
{
	free(ptr);
	return (ret);
}

int	ft_str_is_gt(char *str, int nbr)
{
	int		i;
	int		str_len;
	int		nbr_len;
	char	*int_str;

	int_str = ft_itoa(nbr);
	nbr_len = ft_strlen(int_str);
	str_len = ft_strlen(str);
	if (str_len > nbr_len)
		return (free_int_return(int_str, 1));
	else if (str_len < nbr_len)
		return (free_int_return(int_str, 0));
	i = 0;
	while (str[i])
	{
		if (str[i] > int_str[i])
			return (free_int_return(int_str, 1));
		else if (str[i] < int_str[i])
			return (free_int_return(int_str, 0));
	}
	free(int_str);
	return (0);
}
