# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 07:58:14 by abahdir           #+#    #+#              #
#    Updated: 2021/07/10 19:28:20 by abahdir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = *.c
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	@gcc $(FLAGS) -pthread $(SRC) -o $(NAME)

clean :

fclean :
	@rm -rf philo
run :
	clear ; make re ; ./philosophers 5 800 200 200
re : fclean all	