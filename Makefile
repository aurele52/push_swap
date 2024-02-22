# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audreyer <audreyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 01:52:00 by audreyer          #+#    #+#              #
#    Updated: 2022/08/08 15:54:43 by audreyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#

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

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR),$(FILE))

OBJ = $(SRC:.c=.o)

DOBJ		=	${SRC:.c=.d}

NAME = push_swap

INC = include/push_swap.h

CC = gcc

FLAGS		=	-g -Wall -Werror -Wextra -MMD

RM = rm -rf

all: $(NAME)

-include ${DOBJ}

.c.o:
			$(CC) $(FLAGS) -I include -c $< -o $(<:.c=.o)

$(NAME):	$(LIB) $(OBJ) $(INC) $(INC_LIBFT) $(OBJ_MAIN)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_MAIN) $(LIB) -o $(NAME)

clean:
	${RM} $(OBJ) $(OBJ_MAIN) $(OBJ_BONUS) ${DOBJ_MAIN} ${DOBJ} ${DOBJB} 

fclean: clean
		$(RM) $(NAME) $(BONUS)

re:		fclean all

INC_LIBFT = include/libft.h

BONUS = checker

LIB = $(SRC_DIR)libft.a


SRC_MAIN = $(SRC_DIR)$(FILE_MAIN)
SRC_BONUS = $(SRC_DIR)$(FILE_BONUS)

FILE_MAIN= main.c

FILE_BONUS= checker.c


OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

DOBJB		=	${SRCB:.c=.d}
DOBJ_MAIN = $(SRC_MAIN:.c=.d)

bonus:	$(OBJ) $(INC) $(INC_LIBFT) $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_BONUS) $(LIB) -o $(BONUS)

.PHONY: bonus all clean fclean re .c.o
