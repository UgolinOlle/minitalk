# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 10:28:39 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/11/24 16:55:38 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Variables
HDRDIR      = includes
SRCSDIR     = srcs
LIBSDIR     = libs
SRCS_SERVER = $(SRCSDIR)/server.c
SRCS_CLIENT = $(SRCSDIR)/client.c
SERVER      = server
CLIENT      = client
LIBFT       = $(LIBSDIR)/libft.a

# -- Alias
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HDRDIR) -L$(LIBSDIR) -llibft
RM     = rm -rf


# -- Colors
DEFCOLOR = \033[0;39m
GREEN    = \033[0;92m
YELLOW   = \033[0;93m
BLUE     = \033[0;94m
CYAN     = \033[0;96m

# -- Commands
all: $(SERVER) $(CLIENT)

$(SERVER): $(SRCS_SERVER) $(LIBFT)
	@$(CC) $(FLAGS) -o $@ $(SRCS_SERVER) -L$(LIBSDIR) -lft
	@echo "$(GREEN)Server is ready.$(DEFCOLOR)"

$(CLIENT): $(SRCS_CLIENT) $(LIBFT)
	@$(CC) $(FLAGS) -o $@ $(SRCS_CLIENT) -L$(LIBSDIR) -lft
	@echo "$(GREEN)Client is ready.$(DEFCOLOR)"

$(LIBFT):
	@make -s -C $(LIBSDIR)

clean:
	@make -C $(LIBSDIR) clean
	@echo "$(BLUE)minitalk object files cleaned!$(DEFCOLOR)"

fclean: clean
	@make fclean -s -C $(LIBSDIR)
	@$(RM) $(SERVER) $(CLIENT)
	@echo "$(CYAN)minitalk executable and object files have been cleaned!$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt successfully!$(DEFCOLOR)"

.PHONY: all clean fclean re
