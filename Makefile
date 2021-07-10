# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 07:58:14 by abahdir           #+#    #+#              #
#    Updated: 2021/07/10 09:34:27 by abahdir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
SRC = *.c
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	@gcc -pthread $(SRC) -o philosophers

clean :

fclean :
	@rm -rf philosophers
run :
	clear ; make re ; ./philosophers 5 800 200 200
re : fclean all	