# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elena <Elena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 14:57:13 by frenna            #+#    #+#              #
#    Updated: 2020/02/27 14:17:40 by Elena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIB = libft.a
LIB_PATH = libft/

SRC_NAMES = old_lem.c \
	input.c \
	dinic.c \
	ft_pr_f.c \
	bfs.c \
	dfs.c \
	imin.c \
	ft_dub.c \
	ft_undub.c \
	tf_nodewae.c \
	lem_in.c parse.c valid_ants.c validate.c error_manag.c room_struct_utils.c \
	link_struct_utils.c print_res.c

SRCS = $(addprefix srcs/, $(SRC_NAMES))
SRC_DIR = srcs/

OBJ = $(addprefix obj/, $(SRC_NAMES:%.c=%.o))
OBJ_DIR = obj/

INCLUDES = includes/lem.h

FLAGS =  -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ) $(INCLUDES)
	gcc $(FLAGS) $(LIB_PATH)$(LIB) -I $(INCLUDES) $(OBJ) -o $(NAME)

$(LIB): $(LIB_PATH)
	@make -C $(LIB_PATH)

$(OBJ_DIR):
	@mkdir -p obj
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all

.PHONY: all clean fclean re
