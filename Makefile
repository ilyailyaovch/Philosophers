# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 14:14:46 by pleoma            #+#    #+#              #
#    Updated: 2022/03/21 13:16:21 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror

HEADER = includes/philo.h
OBJ = 	$(patsubst %.c,%.o,$(SRC))
SRC	=	src/philo.c\
		src/fts_args.c\
		src/fts_init.c\
		src/fts_utils.c\
		src/fts_time.c\
		src/fts_threads.c\
		src/fts_routine.c\
		src/fts_death.c\
		src/lib_1.c\
		
.c.o: $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiling $@"

# BETTER
# %.o: %.c $(HEADER)
# 	${CC} ${FLAGS} ${FLAGS_O} -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "compiled $@"

clean :
	@rm -f $(OBJ)
	@echo "Removing obj"

fclean : clean
	@rm -f $(NAME)
	@echo "Removing all"

re : fclean all

.PHONY : all clean fclean re