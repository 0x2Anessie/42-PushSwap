# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 18:23:06 by acatusse          #+#    #+#              #
#    Updated: 2023/05/16 15:17:39 by acatusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f

SRCS = push_swap.c

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

all:
	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re