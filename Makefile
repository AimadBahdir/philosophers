# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 07:58:14 by abahdir           #+#    #+#              #
#    Updated: 2021/07/13 13:57:59 by abahdir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = check_errors.c life_cycle.c philo.c g_time.c life_events.c utils.c

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	@gcc $(FLAGS) -pthread $(SRC) -o $(NAME)
clean :
fclean :
	@rm -rf $(NAME)
re : fclean all	