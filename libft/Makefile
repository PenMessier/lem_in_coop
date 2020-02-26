# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frenna <frenna@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 13:36:52 by frenna            #+#    #+#              #
#    Updated: 2020/02/19 12:12:05 by frenna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_memcpy.c ft_memset.c ft_strcat.c ft_strrchr.c ft_strdel.c ft_strnew.c \
		ft_is_sorted.c ft_strcmp.c ft_strlen.c ft_strsplit.c ft_count_words.c\
		ft_atoi.c ft_mod.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_itoa.c \
		ft_strdup.c ft_strncpy.c ft_free_array.c get_next_line.c
OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRCS)
	gcc $(FLAGS) $(SRCS)

clean: 
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
