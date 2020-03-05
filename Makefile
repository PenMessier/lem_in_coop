# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elena <Elena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 14:57:13 by frenna            #+#    #+#              #
#    Updated: 2020/03/05 21:07:44 by Elena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIB = libft.a
LIB_PATH = libft/

SRC_NAMES = find_paths.c \
	create_link_matrix.c \
	dinic.c \
	ft_pr_f.c \
	bfs.c \
	dfs.c \
	imin.c \
	ft_dub.c \
	ft_undub.c \
	tf_nodewae.c \
	lem_in.c parse.c valid_map_ants.c valid_struct.c error_manag.c room_struct_utils.c \
	link_struct_utils.c assign_room_levels.c \
	print_res.c

SRC_DIR = srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAMES))

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAMES:%.c=%.o))

INCLUDES = includes/lem.h

FLAGS =  -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(LIB) $(NAME)

$(LIB): $(LIB_PATH)
	@make -C $(LIB_PATH)
	
$(NAME): $(OBJ_DIR) $(OBJ) $(INCLUDES)
	gcc $(FLAGS) $(LIB_PATH)$(LIB) -I $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p obj
	@echo "$(NAME): $(GREEN) $(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	/bin/rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(NAME): $(RED)$(LIB) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
