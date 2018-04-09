# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 17:08:13 by vbrovenk          #+#    #+#              #
#    Updated: 2018/04/09 17:08:14 by vbrovenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = algo.c valid.c list.c error.c hashes.c main.c matrix.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = header.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
