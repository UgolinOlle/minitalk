# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 11:49:44 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/10/10 23:42:06 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = includes

SRC_DIRS = str nbr file misc mem
SRC_FILES = $(foreach dir,$(SRC_DIRS),$(wildcard $(SRC_DIR)/$(dir)/*.c))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC_FLAGS = -I $(INC_DIR)

NAME = libft.a

AR = ar rcs
RM = rm -rf
MKDIR = mkdir -p

COLOR_RESET = \033[0m
COLOR_INFO = \033[0;94m
COLOR_SUCCESS = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $@ $^
	@echo "$(COLOR_SUCCESS)$(NAME) has been created successfully.$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@
	@echo "$(COLOR_INFO)Compiling: $<$(COLOR_RESET)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(COLOR_INFO)Object files have been removed.$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_INFO)$(NAME) has been removed.$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
