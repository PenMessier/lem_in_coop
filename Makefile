# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elena <Elena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 14:57:13 by frenna            #+#    #+#              #
#    Updated: 2020/03/23 09:35:48 by Elena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIB = libft.a
LIB_PATH = libft/
READER_NAME = reader

SRC_NAMES = main.c \
	find_paths.c \
	create_link_matrix.c \
	dinic.c \
	ft_pr_f.c \
	bfs.c \
	dfs.c \
	ft_init_meta.c \
	ft_min.c \
	ft_dub.c \
	ft_undub.c \
	ft_nodewae.c \
	ft_parse.c \
	valid_map_ants.c \
	valid_struct.c \
	valid_line_room.c \
	memory_manag.c \
	map_struct_utils.c \
	room_struct_utils.c \
	link_struct_utils.c \
	way_struct_utils.c \
	assign_room_levels.c \
	ft_print_input.c \
	ft_queen.c \
	print_action.c \
	put_error.c

SRC_DIR = srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAMES))

READER_NAMES = reader.c valid_line_room.c reader_write_func.c \
								ft_write_in_file.c
READER_SRCS = $(addprefix $(SRC_DIR), $(READER_NAMES))
READER_OBJ = $(addprefix $(OBJ_DIR), $(READER_NAMES:%.c=%.o))

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAMES:%.c=%.o))

INCLUDES = includes/lem.h

FLAGS =  -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME) $(READER_NAME)

$(LIB): $(LIB_PATH)
	@make -C $(LIB_PATH)

$(NAME): $(OBJ_DIR) $(OBJ) $(INCLUDES) $(LIB)
	gcc $(FLAGS) $(LIB_PATH)$(LIB) -I $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(READER_NAME): $(OBJ_DIR) $(READER_OBJ) $(INCLUDES) $(LIB)
	gcc $(FLAGS) $(LIB_PATH)$(LIB) -I $(INCLUDES) $(READER_OBJ) -o $(READER_NAME)
	@echo "$(READER_NAME): $(GREEN)$(READER_NAME) was created$(RESET)"

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
	/bin/rm -f $(READER_NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(NAME): $(RED)$(LIB) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
