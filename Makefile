# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 22:24:42 by hessabra          #+#    #+#              #
#    Updated: 2019/10/06 05:43:19 by hessabra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC = *.c	Source/*.c\
			readline/*.c\
			quotyred/*.c\
			usetoken/*.c\
    		dolo/*.c\
			here_doc/*.c\
			mixed/*.c
OBJ = x.o

all: $(NAME)

$(NAME):
	@gcc -ltermcap -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
