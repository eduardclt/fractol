# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecloete <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 10:42:41 by ecloete           #+#    #+#              #
#    Updated: 2017/10/19 09:23:21 by ecloete          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	main.c \
		julia.c \
		mandelbrot.c \
		putpixel.c \
		zoom.c \
		chameleon.c \
		mouse.c

LIB = libft/libft.a

FLAGS = -lmlx -framework OpenGL -framework Appkit 

ERROR = -Werror -Wall -Wextra

all:
	make -C ./libft
	@echo "-- LIBFT Compiled --"
	gcc -o $(NAME) $(SRC) $(FLAGS) $(ERROR) $(LIB)
	@echo "-- Fractol Compiled --"

clean:
	$(MAKE) -C ./libft clean
	@rm -f $(LIB)

fclean: clean 
	$(MAKE) -C ./libft fclean
	@rm -f $(LIB)

re: fclean lib all

lib:
	@echo "-- Re-compiling libft --"
	$(MAKE) -C ./libft all
