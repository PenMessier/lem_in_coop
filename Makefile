# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Elena <Elena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 14:57:13 by frenna            #+#    #+#              #
#    Updated: 2020/05/03 19:54:19 by Elena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

READER_NAME = reader

FLAGS = -Wall -Werror -Wextra

INC = ./includes/
INCLUDES = ./$(LIBFT_PATH)includes/
INCLUDE_FILES = $(INC)lem.h \
								$(INC)datatypes.h \
								$(INCLUDES)libft.h

LIB = libft/libft.a

SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

SRC_NAMES = count_index_rooms.c \
			find_paths.c \
			ft_best.c \
			ft_combine_paths.c \
			ft_distribute_ants.c \
			ft_find_more_paths.c \
			ft_find_short_path.c \
			ft_free_list.c \
			ft_full.c \
			ft_line.c \
			ft_list.c \
			ft_modify_graph.c \
			ft_parse.c \
			ft_print_struct.c \
			ft_queen.c \
			ft_refill_map.c \
			ft_restore_graph.c \
			ft_set.c \
			ft_solution_build.c \
			ft_solution_improve.c \
			link_struct_utils.c \
			main.c \
			map_struct_utils.c \
			memory_manag.c \
			print_action.c \
			put_error.c \
			room_struct_utils.c \
			valid_line_room.c \
			valid_map_ants.c \
			valid_struct.c

SRCS = $(addprefix $(SRCS_PATH), $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAMES:.c=.o))

READER_NAMES = reader.c \
							reader_write_func.c \
							ft_write_in_file.c

READER_SRCS = $(addprefix $(SRCS_PATH), $(READER_NAMES))
READER_OBJ = $(addprefix $(OBJ_PATH), $(READER_NAMES:%.c=%.o))

all: $(NAME) $(READER_NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(READER_NAME): $(READER_OBJ) $(LIB) $(OBJ_PATH)valid_line_room.o
	@gcc $(FLAGS) $(READER_OBJ) $(OBJ_PATH)valid_line_room.o $(LIB) -o $(READER_NAME)
	@echo "\033[32mBinary \033[1;32m$(READER_NAME)\033[1;0m\033[32m created.\033[0m"

$(LIB): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)

$(OBJ): $(SRCS) $(INCLUDE_FILES)
	@mkdir -p obj
	@gcc -c $(FLAGS) -I $(INC) -I $(INCLUDES) $(SRCS)
	@mv $(SRC_NAMES:.c=.o) $(OBJ_PATH)
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(OBJ)\033[1m\033[34m done.\033[0m"

$(READER_OBJ): $(READER_SRCS) $(INCLUDE_FILES)
		@gcc -c $(FLAGS) -I $(INC) -I $(INCLUDES) $(READER_SRCS)
		@mv $(READER_NAMES:.c=.o) $(OBJ_PATH)
		@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(READER_OBJ)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJ)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(READER_NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"
	@echo "\033[31mBin \033[1;31m$(READER_NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re
