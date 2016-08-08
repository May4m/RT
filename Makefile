# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/13 13:18:19 by smamba            #+#    #+#              #
#    Updated: 2016/08/08 15:13:56 by smamba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  vector/ft_vector.c \
	  vector/ft_vector_ops.c \
	  vector/ft_vector_arithmetic.c \
	  ft_color.c ft_objects.c ft_ray.c ft_stack.c \
	  window.c scene1.c utils.c\
	  engine/operations.c \
	  engine/shading_model.c \
	  engine/core.c \
	  engine/intersections.c \
	  engine/ft_normals.c \
	  matrix/ft_matrix.c \
	  matrix/ft_matrix_ops.c \

NAME = rtv1

all: $(NAME)

$(DEBUG): ARGS = -Wall -Werror -Wextra

$(NAME):
	@gcc $(SRC) $(ARGS) -I. -framework AppKit -framework OpenGL -I vector -lmlx -lm -o $(NAME) -I matrix/

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
