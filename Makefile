##
## EPITECH PROJECT, 2024
## shell
## File description:
## Makefile for shell
##

SRC = 	main.c 						\
		src/commands.c 				\
		src/env.c 					\
		src/input.c 				\
		src/get_cmd.c 				\
		src/get_path.c 				\
		src/shell.c 				\
		src/status.c 				\
		src/utils_env.c 			\
		src/utils/my_strcmp.c		\
		src/utils/usage.c 			\
		src/utils/stwa.c 			\
		src/utils/my_strcat.c 		\
		src/utils/my_strcpy.c 		\
		src/utils/my_strncmp.c 		\
		src/utils/my_strchr.c 		\
		src/utils/my_strdup.c 		\
		src/utils/my_strlen.c 		\
		src/printf/mini_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	= -Wall -Wextra

CPPFLAGS = -iquote ./include

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
