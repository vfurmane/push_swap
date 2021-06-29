/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 23:02:44 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/29 10:57:16 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	*ft_memdup(const void *ptr, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	ft_memswap(void *ptr1, void *ptr2, size_t len);
void	ft_swap4(int32_t *nbr1, int32_t *nbr2);

#endif
