# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 14:14:46 by pleoma            #+#    #+#              #
#    Updated: 2022/02/27 14:20:04 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror

HEADER = includes/philo.h
OBJ = 	$(patsubst %.c,%.o,$(SRC))
SRC	=	src/philo.c\

.c.o: $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiling $@"

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS)  $(OBJ) -o $@
	@echo "Compiling $@"

clean :
	@rm -f $(OBJ)
	@echo "Removing obj"

fclean : clean
	@rm -f $(NAME)
	@echo "Removing all"

re : fclean all

.PHONY : all clean fclean re