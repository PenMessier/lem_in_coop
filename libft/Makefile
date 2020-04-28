# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elena <Elena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 13:36:52 by frenna            #+#    #+#              #
#    Updated: 2020/04/27 19:06:33 by Elena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes/

SRC_NAMES = ft_atoi.c \
		ft_count_words.c \
		ft_free_array.c \
		ft_is_sorted.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_mod.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strrchr.c \
		ft_strsplit.c \
		get_next_line.c

SRCS_PATH = srcs/
OBJ_PATH = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAMES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ): $(INCLUDES)libft.h $(SRCS)
	@mkdir -p obj
	@gcc -c $(FLAGS) -I $(INCLUDES) $(SRCS)
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(OBJ)\033[1m\033[34m done.\033[0m"
	@mv $(SRC_NAMES:.c=.o) $(OBJ_PATH)

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJ)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
