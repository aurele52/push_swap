# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audreyer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 22:50:22 by audreyer          #+#    #+#              #
#    Updated: 2022/07/10 17:47:37 by audreyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc

FLAG = -Wall -Werror -Wextra -g3

SRC_DIR = src/

OBJ_DIR = obj/

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

.c.o:
	$(CC) $(FLAG) -I include -c $< -o $(subst src/,obj/,$(<:.c=.o))

INC = include/push_swap.h

INC_LIBFT = include/libft.h

LIB = libft.a

all:	$(LIB) $(NAME) $(BONUS)

$(NAME):	$(OBJ) $(INC) $(INC_LIBFT) $(OBJ_MAIN)
	$(CC) $(FLAG) $(subst src/,obj/,$(OBJ) $(OBJ_MAIN)) $(LIB) -o $(NAME)

clean:
	rm -f $(subst src/,obj/,$(OBJ) $(OBJ_MAIN) $(OBJ_BONUS)) libft.a

fclean:	clean
	rm -f $(NAME) $(BONUS)

$(BONUS):	$(OBJ) $(INC) $(INC_LIBFT) $(OBJ_BONUS)
	$(CC) $(FLAG) $(subst src/,obj/,$(OBJ) $(OBJ_BONUS)) $(LIB) -o $(BONUS)

fclean_bonus :
	rm -f $(subst src/,obj/,$(OBJ) $(OBJ_CHECKER)) $(BONUS)

$(LIB)	:
	make -C ./libft/
	rm -f libft.a
	cp libft/libft.a .

re			: fclean all 

git:
	make git -C ./libft/
	rm -f libft.a
	make fclean
	git add obj
	git add src
	git add Makefile
	git add include/
	read S; git commit -m $${S}
	git push

fini:
	rm libft
	cp -r ../libft .
	rm -rf libft/.git
	make fclean -C ./libft/
	git add libft
	make git

.PHONY: all clean fclean re libft
