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
	  ft_camera.c \
	  manager/app_environ.c\
	  manager/window.c\
	  vector/ft_vector.c \
	  vector/ft_vector_ops.c \
	  vector/ft_vector_arithmetic.c \
	  ft_color.c ft_objects.c ft_ray.c ft_stack.c \
	  scene1.c utils.c\
	  engine/operations.c \
	  engine/shading_model.c \
	  engine/core.c \
	  engine/intersections.c \
	  engine/ft_normals.c \
	  matrix/ft_matrix.c \
	  matrix/ft_matrix_ops.c \
	  matrix/matrix_utils.c\
	  matrix/garbage_collector.c\
	  matrix/matrix_ops2.c

NAME = rtv1

LIBS = minilibx/ -L libft/
all: $(NAME)

$(DEBUG): ARGS = -Wall -Werror -Wextra

$(NAME):
	make -C libft/ all
	@gcc $(SRC) $(ARGS) -I. -I libft/ -L $(LIBS) -I minilibx -I vector \
			-lft -lmlx -lXext -lm -o $(NAME) -I matrix/

clean:
	make -C libft/ clean
	@rm -f $(NAME)

fclean: clean
	make -C libft/ fclean

re: fclean all
