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
FILE_MAIN= main.c
FILE_BONUS= checker.c

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR),$(FILE))
SRC_MAIN = $(SRC_DIR)$(FILE_MAIN)
SRC_BONUS = $(SRC_DIR)$(FILE_BONUS)

OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

DOBJ		=	${SRC:.c=.d}
DOBJ_BONUS		=	${SRC_BONUS:.c=.d}
DOBJ_MAIN = $(SRC_MAIN:.c=.d)

NAME = push_swap
BONUS = checker

INC = include/push_swap.h

CC = gcc

FLAGS		=	-g -Wall -Werror -Wextra -MMD

RM = rm -rf

all: $(NAME)

-include ${DOBJ} ${DOBJ_MAIN} ${DOBJ_BONUS}

.c.o:
			$(CC) $(FLAGS) -I include -c $< -o $(<:.c=.o)

$(NAME):	$(LIB) $(OBJ) $(INC) $(INC_LIBFT) $(OBJ_MAIN)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_MAIN) $(LIB) -o $(NAME)


$(BONUS):	$(OBJ) $(INC) $(INC_LIBFT) $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_BONUS) $(LIB) -o $(BONUS)

clean:
	${RM} $(OBJ) $(OBJ_MAIN) $(OBJ_BONUS) ${DOBJ_MAIN} ${DOBJ} ${DOBJ_BONUS} 

fclean: clean
		$(RM) $(NAME) $(BONUS)

re:		fclean all

INC_LIBFT = include/libft.h

LIB = $(SRC_DIR)libft.a

.PHONY: bonus all clean fclean re .c.o
