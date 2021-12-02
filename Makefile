# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2021/12/02 17:07:42 by msierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	fdf

SRCS		=	./includes/ft_atoi.c				\
				./includes/ft_bzero.c				\
				./includes/ft_calloc.c				\
				./includes/ft_putchar_fd.c			\
				./includes/ft_split.c				\
				./includes/ft_strdup.c				\
				./includes/ft_strlen.c				\
				./includes/ft_substr.c				\
				./includes/ft_toupper.c				\
				./includes/get_next_line_utils.c	\
		  		./includes/get_next_line.c			\
				./sources/fdf.c						\
				./sources/ft_bresenham.c			\
				./sources/ft_drawline.c				\
				./sources/ft_error.c				\
				./sources/ft_getcolor.c				\
				./sources/ft_imagedraw.c			\
				./sources/ft_mapsize.c				\
				./sources/ft_parse_utils.c			\
				./sources/ft_parse_utils2.c			\
				./sources/ft_parse.c				\
				./sources/ft_parsecolor.c			\


PINK = \033[1;35m
GREEN = \033[1;32m
BLUE = \033[1;36m
RESET = \033[0m

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS 	= -Wall -Werror -Wextra

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all	:		$(NAME)

$(NAME)	:	start $(OBJS)
			@$(CC) $(OBJS) -o $(NAME) -fsanitize=address -lmlx -framework OpenGL -framework AppKit
			@echo "$(RESET)Done"
			@echo "$(GREEN)==========WELLDONE==========$(RESET)"
			@echo "Success creating $(NAME) file"

start:
			@echo "$(BLUE)==========CREATING: $(GREEN)$(NAME)$(BLUE)==========$(PINK)"

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ 

clean:	
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
