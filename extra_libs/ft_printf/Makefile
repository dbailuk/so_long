# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 15:41:40 by dbailuk           #+#    #+#              #
#    Updated: 2024/12/07 16:39:00 by dbailuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS =	ft_printf.c ft_putchr.c ft_putstr.c ft_putptr.c \
		ft_putnbr.c ft_putnbr_uns.c ft_puthex.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

