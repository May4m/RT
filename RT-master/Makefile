# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/13 13:18:19 by smamba            #+#    #+#              #
#    Updated: 2016/07/31 16:00:22 by smamba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/main.c srcs/ft_vector.c srcs/ft_vector_ops.c srcs/ft_vector_arithmetic.c \
	  srcs/ft_color.c srcs/ft_objects.c srcs/ft_ray.c srcs/ft_spheres.c engine/tracer.c \
	  srcs/intersections.c srcs/window.c srcs/scene1.c srcs/utils.c srcs/shading_model.c \
	  srcs/ft_normals.c

NAME = rtv1

all: $(NAME)

$(DEBUG): ARGS = -Wall -Werror -Wextra

$(NAME):
	@gcc $(SRC) $(ARGS) -I. -lmlx -framework AppKit -framework OpenGL -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
