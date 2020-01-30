# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 17:50:19 by gstarvin          #+#    #+#              #
#    Updated: 2019/09/10 19:41:05 by gstarvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = *.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC)
		ar rc $(NAME) *.o

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re:	fclean all
