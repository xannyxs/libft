# ************************************************************************** #
#                                                                            #
#                                                        ::::::::            #
#   Makefile                                           :+:    :+:            #
#                                                     +:+                    #
#   By: xvoorvaa <marvin@codam.nl>                   +#+                     #
#                                                   +#+                      #
#   Created: 2020/11/20 14:55:34 by xvoorvaa      #+#    #+#                 #
#   Updated: 2020/11/20 14:55:35 by xvoorvaa      ########   odam.nl         #
#                                                                            #
# ************************************************************************** #

NAME			=	libft.a
CFLAGS			=	-Wall -Werror -Wextra
SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c \
					ft_strlcat.c  ft_strncmp.c ft_substr.c ft_atoi.c \
					ft_isalpha.c ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c  ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c \
					ft_putstr_fd.c  ft_strjoin.c ft_strtrim.c ft_itoa.c \
					ft_memcpy.c ft_split.c ft_strmapi.c ft_strrchr.c \
					ft_memccpy.c ft_memset.c \

OBJS			=	$(SRCS:.c=.o)

GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

START			= "$(BLUE)---\nStarting...!\n---$(NC)"
MESSAGE			= "$(BLUE)---\nCompiling done! Run ./$(NAME)\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files...$(NC)"

all:		$(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@clear
	@echo $(START)
	@printf $(COMP_MESSAGE) $(SRCS)
	@echo $(MESSAGE)

clean:
	@echo "\n"
	@rm -f $(OBJS)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:		clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME_EXE)

re:			fclean all

.PHONY:		all leaks clean fclean re
