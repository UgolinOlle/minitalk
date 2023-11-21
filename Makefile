# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 10:28:39 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/11/21 11:59:41 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Variables
HDRDIR  = includes
SRCSDIR = srcs
LIBSDIR = libs
SRCS_SERVER = $(SRCSDIR)/server.c
SRCS_CLIENT = $(SRCSDIR)/client.c
SERVER  = server
CLIENT  = client

# -- Alias
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBSDIR)/includes -L$(LIBSDIR) -llibft
RM     = rm -rf

# -- Colors
DEFCOLOR = \033[0;39m
GREEN    = \033[0;92m
YELLOW   = \033[0;93m
BLUE     = \033[0;94m
CYAN     = \033[0;96m

# -- Commands
all:
	@make -s -C $(LIBSDIR)
	@gcc $(FLAGS) $(SRCS_SERVER) -o $(SERVER)
	@gcc $(FLAGS) $(SRCS_CLIENT) -o $(CLIENT)
	@echo "$(GREEN)Server And Client Are Ready!$(DEFCOLOR)"

clean:
	@make clean -s -C $(LIBSDIR)
	@echo "$(BLUE)minitalk object files cleaned!$(DEFCOLOR)"

fclean: clean
	@make clean -s -C $(LIBSDIR)
	@${RM} -f $(SERVER) $(CLIENT)
	@echo "$(CYAN)minitalk executable and object files has been cleaned!$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt successfully!$(DEFCOLOR)"

.PHONY: all clean fclean re
