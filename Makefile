# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 22:24:42 by hessabra          #+#    #+#              #
#    Updated: 2019/10/23 16:18:12 by hessabra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC =	Source/dfre.c Source/dfree_int.c Source/ft_addtotab.c Source/ft_atoi.c Source/ft_bzero.c Source/ft_cased.c Source/ft_cases.c Source/ft_conversion.c Source/ft_entier.c Source/ft_flags.c Source/ft_freesub.c Source/ft_freetab.c Source/ft_isalnum.c Source/ft_isalpha.c Source/ft_isascii.c Source/ft_isdigit.c Source/ft_islower.c Source/ft_isprint.c Source/ft_isspace.c Source/ft_isupper.c Source/ft_itoa.c Source/ft_jandf.c Source/ft_lenth.c Source/ft_lstadd.c Source/ft_lstdel.c Source/ft_lstdelone.c Source/ft_lstiter.c Source/ft_lstlen.c Source/ft_lstmap.c Source/ft_lstnew.c Source/ft_max.c Source/ft_mema.c Source/ft_memalloc.c Source/ft_memccpy.c Source/ft_memchr.c Source/ft_memcmp.c Source/ft_memcpy.c Source/ft_memdel.c Source/ft_memmove.c Source/ft_memset.c Source/ft_nbrdel.c Source/ft_parite.c Source/ft_pourcent.c Source/ft_precision.c Source/ft_printf.c Source/ft_putchar.c Source/ft_putchar_fd.c Source/ft_putendl.c Source/ft_putendl_fd.c Source/ft_putnbr.c Source/ft_putnbr_fd.c Source/ft_putstr.c Source/ft_putstr_fd.c Source/ft_rcased.c Source/ft_searchnreplace.c Source/ft_split.c Source/ft_strcat.c Source/ft_strchr.c Source/ft_strclr.c Source/ft_strcmp.c Source/ft_strcpy.c Source/ft_strdel.c Source/ft_strdup.c Source/ft_strequ.c Source/ft_striter.c Source/ft_striteri.c Source/ft_strjoin.c Source/ft_strlcat.c Source/ft_strlen.c Source/ft_strmap.c Source/ft_strmapi.c Source/ft_strncat.c Source/ft_strncmp.c Source/ft_strncpy.c Source/ft_strnequ.c Source/ft_strnew.c Source/ft_strnstr.c Source/ft_strrchr.c Source/ft_strsplit.c Source/ft_strstr.c Source/ft_strsub.c Source/ft_strtrim.c Source/ft_subtochar.c Source/ft_tablen.c Source/ft_tolower.c Source/ft_toupper.c Source/ft_white.c Source/ft_width.c Source/splitbs.c Source/tfree.c\
		readline/ft_copy_cut.c readline/ft_cursor_move.c readline/ft_delect_char.c readline/ft_initialize.c readline/ft_key_detect.c readline/ft_line_manage.c readline/ft_manage_history.c readline/ft_move_addition.c readline/ft_move_addition1.c readline/ft_readline.c readline/ft_sig_handlers.c readline/ft_tools.c\
		quotyred/quotyred.c quotyred/quotyred_2.c quotyred/quotyred_3.c quotyred/quotyred_4.c\
		usetoken/usetoken.c usetoken/usetoken_2.c usetoken/usetoken_3.c\
		dolo/dolo.c dolo/dolo_2.c dolo/dolosuite.c\
		here_doc/here_doc.c here_doc/here_doc_2.c here_doc/heredocsuite.c\
		synerr/synerr.c synerr/synerr_2.c\
		 mixed/mixed.c mixed/mixed_2.c\
		add_quotynbr.c aloc.c backslash1.c builtin.c cdi.c cdira.c charisint.c checking.c counpi.c ech.c exi.c ft_intet.c ft_isalnu.c jointetoile.c know.c line.c mini.c mini_2.c mini_3.c nbr_arg.c nbrope.c open_fds.c pipe.c pipe_2.c pipe_3.c ppvr.c quotes.c quotes_2.c quotywhile.c setenv.c tabjoin.c triplp.c unstenv.c
OBJ = x.o

all: $(NAME)

$(NAME):
	@gcc -ltermcap -Wall -Wextra -Werror -g $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
