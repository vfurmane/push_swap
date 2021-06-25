# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 13:23:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/06/25 16:42:39 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCS		= $(addprefix srcs/, main.c)
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

# remove fsanitize
all:		CFLAGS+= -fsanitize=address
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
