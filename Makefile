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
CFLAGS		=	-Wall -Wextra -Werror -O3 -pedantic -std=c11


PRINTF_SRC := ft_printf/ft_printf.c ft_printf/conversion.c \
              ft_printf/utils/convert_hex.c ft_printf/utils/ft_numlen.c \
              ft_printf/print/print_c.c ft_printf/print/print_id.c \
              ft_printf/print/print_p.c ft_printf/print/print_perc.c \
              ft_printf/print/print_s.c ft_printf/print/print_u.c \
              ft_printf/print/print_x.c

FILES := ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
				 ft_strlcat.c ft_strncmp.c ft_substr.c count_digits.c \
				 ft_isalpha.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
				 ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
				 ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c \
				 ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c \
				 ft_putstr_fd.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
				 ft_memcpy.c ft_split.c ft_strmapi.c ft_strrchr.c \
				 ft_memccpy.c ft_memset.c ft_free_array.c ft_strcmp.c \
				 ft_strjoin_free.c ft_print_array.c ft_atol.c ft_ltoa.c \
				 $(PRINTF_SRC)

HEADERS		:=	-I inc
SRCS			:=	$(addprefix src/, $(FILES))
OBJS			:=	$(SRCS:.c=.o)

PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

START			=	"$(BLUE)---\nStarting...!\n---\n$(RESET)"
MESSAGE			=	"$(BLUE)---\nCompiling done!\n---\n$(RESET)"
COMP_MESSAGE	=	"$(GREEN)Building C object... $(RESET)%-33.33s\r\n"
REM_MESSAGE		=	"$(RED)Removing files...$(RESET)"

all:	$(NAME)

%.o: %.c
	@$(CC) -c $^ -o $@ $(FLAGS) $(HEADERS)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf $(START)
	@printf $(COMP_MESSAGE) $(SRCS)
	@printf $(MESSAGE)

clean:
	@printf "\n"
	rm -f $(OBJS)
	@printf "\n"


fclean:		clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re:			fclean all

so:
	$(CC) -fPIC $(CFLAGS) $(HEADERS) -c $(SRCS)
	$(CC) -shared -o libft.so $(OBJS) -nostartfiles

.PHONY:		all clean fclean re
