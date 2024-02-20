# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audreyer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 22:50:22 by audreyer          #+#    #+#              #
#    Updated: 2022/07/21 19:37:22 by audreyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc

FLAG = -Wall -Werror -Wextra

SRC_DIR = src/

OBJ_DIR = src/

FILE_MAIN= main.c

FILE_BONUS= checker.c

FILE=	aurele_sort_utils_2.c	\
	aurele_sort_utils.c	\
	bazar.c	\
	push.c	\
	push_swap.c	\
	push_swap_utils.c	\
	rotate2.c	\
	rotate.c	\
	ft_atoitest.c	\
	swap.c

SRC_MAIN = $(SRC_DIR)$(FILE_MAIN)

SRC_BONUS = $(SRC_DIR)$(FILE_BONUS)

SRC = $(addprefix $(SRC_DIR),$(FILE))

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INC = include/push_swap.h

INC_LIBFT = include/libft.h

LIB = $(SRC_DIR)libft.a

all:
	make $(NAME)

bonus:$(BONUS)

$(NAME):	$(LIB) $(OBJ) $(INC) $(INC_LIBFT) $(OBJ_MAIN)
	$(CC) $(FLAG) $(OBJ) $(OBJ_MAIN) $(LIB) -o $(NAME)

.c.o:
	$(CC) $(FLAG) -I include -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJ) $(OBJ_MAIN) $(OBJ_BONUS)

fclean:	clean
	rm -f $(NAME) $(BONUS)

$(BONUS):	$(OBJ) $(INC) $(INC_LIBFT) $(OBJ_BONUS)
	$(CC) $(FLAG) $(OBJ) $(OBJ_BONUS) $(LIB) -o $(BONUS)

fclean_bonus :
	rm -f $(OBJ) $(OBJ_CHECKER) $(BONUS)

re			: fclean all 

.PHONY: bonus all clean fclean re libft
