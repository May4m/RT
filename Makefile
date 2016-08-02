# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/13 13:18:19 by smamba            #+#    #+#              #
#    Updated: 2016/08/02 13:51:44 by simzam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c ft_vector.c ft_vector_ops.c ft_vector_arithmetic.c \
	  ft_color.c ft_objects.c ft_ray.c ft_spheres.c engine/tracer.c \
	  intersections.c window.c scene1.c utils.c shading_model.c \
	  ft_normals.c constructors.c

LIXLIB=		-L/usr/lib/X11 -lmlx -lXext -lX11 -lm
MACLIB=		-L/usr/lib/ -lmlx -framework OpenGL -framework AppKit

NAME = rtv1

all: $(NAME)

$(DEBUG): ARGS = -Wall -Werror -Wextra

$(NAME):

ifeq ($(shell) uname, Linux)
	@gcc $(SRC) $(ARGS) -I. $(MACLIB) -o $(NAME)
else
	@gcc $(SRC) $(ARGS) -I. $(LIXLIB) -o $(NAME)
endif

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
