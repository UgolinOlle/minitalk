# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 11:49:44 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/09/22 13:40:58 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR		= srcs
OBJDIR		= ../objs
HDRDIR		= ../includes

SRCS		= $(wildcard $(SRCDIR)/*.c)
OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
AR			= ar rcs

DEFCOLOR	= \033[0;39m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
CYAN		= \033[0;96m

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)Libft successfully compiled.$(DEFCOLOR)"

${OBJDIR}%.o : ${SRCDIR}%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling: $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)Libft objects as been clean.$(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)Libft executable as been clean.$(DEFCOLOR)"


re: fclean all
	@echo "${GREEN}Libft as been clean and rebuilt correctly.${DEFCOLOR}"

.PHONY:		all clean fclean re
