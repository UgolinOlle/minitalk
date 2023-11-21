# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 11:29:12 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/10/04 14:46:30 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR   = includes
SRCDIR   = srcs
OBJDIR   = objs
LIBDIR   = lib

SRCS     = $(wildcard $(SRCDIR)/*.c)
OBJS     = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME     = libftprintf.a
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
RM       = rm -rf
AR       = ar rcs

DEFCOLOR = \033[0;39m
GREEN    = \033[0;92m
YELLOW   = \033[0;93m
BLUE     = \033[0;94m
CYAN     = \033[0;96m

all: $(NAME)

$(NAME): $(OBJS)
	@cp $(LIBDIR)/libft.a .
	@mv libft.a $(NAME)
	@$(CC) $(CFLAGS) -I $(HDRDIR) $(OBJS) $(LIBDIR)/libft.a -o $(NAME)
	# @$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf has been successfully compiled$(DEFCOLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@make -C $(LIBDIR)
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling: $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C ${LIBDIR}
	@echo "$(BLUE)ft_printf object files cleaned!$(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@${RM} -f ${LIBDIR}/libft.a
	@echo "$(CYAN)ft_printf executable has been cleaned!$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt successfully!$(DEFCOLOR)"

.PHONY: all clean fclean re
