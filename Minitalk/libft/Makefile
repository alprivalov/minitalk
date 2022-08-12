# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alprival <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 11:57:09 by alprival          #+#    #+#              #
#    Updated: 2022/04/16 14:56:38 by alprival         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c \

OBJ		= $(SRC:.c=.o)

OBJBS	= $(SRCBS:.c=.o)

CC		= gcc -g

RM		= rm -f

CFLAGS = -Werror -Wextra -Wall 

$(NAME):	$(OBJ)
	ar rcs libftprintf.a $(OBJ)

bonus:	$(OBJBS)
	ar rcs libftprintf.a $(OBJBS)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJBS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
