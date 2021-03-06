/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 23:02:44 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/02 11:24:52 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <stdlib.h>

typedef struct s_next
{
	struct s_next	*next;
}					t_next;

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_isdigit(int chr);
char	*ft_itoa(int nbr);
void	ft_lstadd_back(void *lst, void *new);
void	ft_lstadd_front(void *lst, void *new);
void	*ft_lstcpy(void *lst, size_t elm_len);
void	*ft_lstdup(void *lst);
void	*ft_lstlast(void *lst);
int		ft_lstsize(void *lst);
void	*ft_memdup(const void *ptr, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	ft_memswap(void *ptr1, void *ptr2, size_t len);
int		ft_str_is_gt(char *str, int nbr);
int		ft_str_is_lt(char *str, int nbr);
int		ft_strlen(const char *str);
void	ft_swap4(int32_t *nbr1, int32_t *nbr2);

#endif
