# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:23:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/09/03 09:37:26 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCS		= $(addprefix srcs/, align.c check_arguments.c main.c parse_arguments.c perform_push.c perform_rotate.c perform_reverse_rotate.c perform_swap.c stack_elm.c \
			  $(addprefix utils/, ft_atoi.c ft_atol.c ft_isdigit.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstdup.c ft_lstcpy.c ft_lstlast.c ft_lstsize.c ft_memdup.c ft_memmove.c ft_str_is_gt.c ft_str_is_lt.c ft_strlen.c ft_swap4.c))
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

# remove fsanitize
all:		CFLAGS+= -fsanitize=address -g3
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

bonus:		all

# remove nosan
nosan:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

# Remove nosan
.PHONY:		all bonus nosan clean fclean re
