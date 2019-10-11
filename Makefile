# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 22:24:42 by hessabra          #+#    #+#              #
#    Updated: 2019/10/11 01:10:42 by hessabra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC =	Source/*.c\
		readline/*.c\
		quotyred/*.c\
		usetoken/*.c\
		dolo/*.c\
		here_doc/*.c\
		synerr/*.c\
		mixed/*.c\
		*.c
OBJ = x.o

all: $(NAME)

$(NAME):
	@gcc -ltermcap -Wall -Wextra -Werror -g $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
