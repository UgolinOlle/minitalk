# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 10:28:39 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/11/21 10:32:13 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR = includes
OBJDIR = objs
LIBDIR = lib
SERVER = server
CLIENT = client

SRCS_SERVER = srcs/server.c
OBJS_SERVER = $($(SRCS_SERVER)=$(OBJDIR)/%.o)

SRCS_CLIENT = srcs/client.c
OBJS_CLIENT = $($(SRCS_CLIENT)=$(OBJDIR)/%.o)

CC     = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBDIR)/includes -L$(LIBDIR) -lftprintf
RM     = rm -rf
AR     = ar rcs

DEFCOLOR = \033[0;39m
GREEN    = \033[0;92m
YELLOW   = \033[0;93m
BLUE     = \033[0;94m
CYAN     = \033[0;96m

all:
	@make -s -C $(LIBDIR)
	@$(CC) $(CFLAGS) $(SRCS_SERVER) -o $(SERVER)
	@$(CC) $(CFLAGS) $(SRCS_CLIENT) -o $(CLIENT)
	@echo "$(GREEN)minitalk as been compiled successfully.$(DEFCOLOR)"

clean:
	@$(RM) -r $(OBJDIR)
	@echo "$(BLUE)minitalk object files cleaned!$(DEFCOLOR)"

fclean: clean
	@$(RM) -r $(OBJDIR)
	@${RM} -f $(SERVER) $(CLIENT)
	@echo "$(CYAN)minitalk executable and object files has been cleaned!$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt successfully!$(DEFCOLOR)"

.PHONY: all clean fclean re
