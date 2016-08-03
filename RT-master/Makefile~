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

SRC = main.c ft_vector.c ft_vector_ops.c ft_vector_arithmetic.c \
	  ft_color.c ft_objects.c ft_ray.c ft_spheres.c engine/tracer.c \
	  intersections.c window.c scene1.c utils.c shading_model.c \
	  ft_normals.c

NAME = rtv1

all: $(NAME)

$(DEBUG): ARGS = -Wall -Werror -Wextra

$(NAME):
	@gcc $(SRC) $(ARGS) -I. -lmlx -framework AppKit -framework OpenGL -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
