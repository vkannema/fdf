# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 18:00:48 by vkannema          #+#    #+#              #
#    Updated: 2017/02/26 17:52:13 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
		display.c \
		perspec.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = -L./Libft/ -lftprintf -L./minilibx_macos -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./Libft
	make -C ./minilibx_macos
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(FRAMEWORK)

%.o: %.c
	gcc $(FLAGS) -I./Libft/includes -I./minilibx_macos -c $?

clean:
	rm -f $(OBJ)
	make clean -C ./Libft/
	make clean -C ./minilibx_macos/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./Libft/

re: fclean all
