# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 12:53:41 by vkannema          #+#    #+#              #
#    Updated: 2017/03/01 18:16:56 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
		display.c \
		perspec.c \
		parser.c \
		hooks.c \
		keyboard1.c \
		keyboard.c \
		print.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = -L./Libft/ -lftprintf -L./minilibx_macos -lmlx

LIB_CAP = -L./Libft/ -lftprintf -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./Libft
	make -C ./minilibx_macos
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(FRAMEWORK)

%.o: %.c
	gcc $(FLAGS) -I./Libft/includes -I./minilibx_macos -c $?

capitan : $(OBJ)
	make -C ./Libft
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_CAP) $(FRAMEWORK)

clean:
	rm -f $(OBJ)
	make clean -C ./Libft/
	make clean -C ./minilibx_macos/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./Libft/

re: fclean all
