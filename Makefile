# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 22:24:42 by hessabra          #+#    #+#              #
#    Updated: 2019/09/24 21:41:33 by hessabra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC = *.c Source/*.c readline/*.c
OBJ = x.o

all: $(NAME)

$(NAME):
	@gcc -ltermcap  $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
