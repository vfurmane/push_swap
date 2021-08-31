/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:12:41 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/31 12:02:10 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_count_digits(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	i += nbr < 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int				i;
	int				len;
	char			*str;
	unsigned int	nb;

	len = ft_count_digits(nbr);
	str = malloc((len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	if (nbr == 0)
		str[0] = '0';
	if (nbr <= 0)
		nb = -nbr;
	else
		nb = nbr;
	i = len;
	while (nb)
	{
		i--;
		str[i] = nb % 10 + '0';
		nb /= 10;
	}
	str[len] = '\0';
	return (str);
}
