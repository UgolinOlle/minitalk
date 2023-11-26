# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 10:28:39 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/11/26 16:28:23 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Variables
HDRDIR       = includes
SRCSDIR      = srcs
LIBSDIR      = libs
SERVER       = server
CLIENT       = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS_SERVER       = $(SRCSDIR)/server.c
SRCS_CLIENT       = $(SRCSDIR)/client.c
SRCS_SERVER_BONUS = $(SRCSDIR)/server_bonus.c
SRCS_CLIENT_BONUS = $(SRCSDIR)/client_bonus.c
LIBFT             = $(LIBSDIR)/libft.a

# -- Alias
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HDRDIR) -L$(LIBSDIR) -llibft -fsanitize=address
RM     = rm -rf

# -- Colors
COLOR_RESET = \033[0m
COLOR_INFO = \033[0;94m
COLOR_SUCCESS = \033[0;92m

all: $(SERVER) $(CLIENT)

# -- Compilation
$(SERVER): $(SRCS_SERVER) $(LIBFT)
	@$(CC) $(FLAGS) -o $@ $(SRCS_SERVER) -L$(LIBSDIR) -lft
	@echo "$(COLOR_SUCCESS)[MANDATORY] - Server is ready.$(COLOR_RESET)"

$(CLIENT): $(SRCS_CLIENT) $(LIBFT)
	@$(CC) $(FLAGS) -o $@ $(SRCS_CLIENT) -L$(LIBSDIR) -lft
	@echo "$(COLOR_SUCCESS)[MANDATORY] - Client is ready.$(COLOR_RESET)"

$(SERVER_BONUS): $(SRCS_SERVER_BONUS) $(LIBFT)
	@$(CC) $(FLAGS) -o $@ $(SRCS_SERVER_BONUS) -L$(LIBSDIR) -lft
	@echo "$(COLOR_SUCCESS)[BONUS] - Server is ready.$(COLOR_RESET)"

$(CLIENT_BONUS): $(SRCS_CLIENT_BONUS) $(LIBFT)
	@$(CC) $(FLAGS) -o $@ $(SRCS_CLIENT_BONUS) -L$(LIBSDIR) -lft
	@echo "$(COLOR_SUCCESS)[BONUS] - Client is ready.$(COLOR_RESET)"

$(LIBFT):
	@make -s -C $(LIBSDIR)

# -- Commands
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	@make -C $(LIBSDIR) clean
	@echo "$(COLOR_INFO)minitalk object files cleaned!$(COLOR_RESET)"

fclean: clean
	@make fclean -s -C $(LIBSDIR)
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "$(COLOR_INFO)minitalk executable files have been cleaned!$(COLOR_RESET)"

re: fclean all
	@echo "$(COLOR_SUCCESS)Cleaned and rebuilt successfully!$(COLOR_RESET)"

norminette:
	@norminette

.PHONY: all bonus clean fclean re
