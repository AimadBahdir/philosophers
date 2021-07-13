# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 07:58:14 by abahdir           #+#    #+#              #
#    Updated: 2021/07/13 13:53:51 by abahdir          ###   ########.fr        #
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
	@rm -rf $(NAME)
re : fclean all	