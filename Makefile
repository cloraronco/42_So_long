# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:54:47 by clora-ro          #+#    #+#              #
#    Updated: 2022/05/09 10:47:53 by clora-ro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = so_long

# Fichiers source
SRCS = action.c \
	   check_wall.c \
	   checker_map_wall.c \
	   checker_map.c \
	   close.c \
	   main.c \
	   map_init.c \
	   map_read.c \
	   move.c \
	   position.c \
	   get_next_line.c

# Fichiers objets correspondants
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Werror -Wextra

# Commande pour supprimer des fichiers
RM = rm -f

# Bibliothèques
LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx.a

# Règle par défaut
all: libft minilibx $(NAME)

libft:
	$(MAKE) -C libft

minilibx:
	$(MAKE) -C minilibx

# Règle de construction de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm -lbsd
# Pour macOS, ajouter les options -framework
ifeq ($(shell uname -s),Darwin)
	$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm -lbsd -framework OpenGL -framework AppKit
endif

# Règle de construction des fichiers objets
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -Iincludes -DBUFFER_SIZE=20 -c $< -o $@

# Nettoyage
clean:
	$(RM) -r $(OBJS_DIR)
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft minilibx

# NAME 		= so_long

# SRCS		=	action.c \
# 				checker_map_wall.c \
# 				checker_map.c \
# 				check_wall.c \
# 				close.c \
# 				main.c \
# 				map_init.c \
# 				map_read.c \
# 				move.c \
# 				position.c \
# 				get_next_line.c

# OBJS		= $(SRCS:.c=.o)

# CC			= gcc

# CFLAGS		= -Wall -Werror -Wextra

# RM			= rm -f

# CLEAN		= CLEAN

# all			: libft minilibx $(NAME)

# libft		:
# 			$(MAKE) -C libft

# minilibx	:
# 			$(MAKE) -C minilibx

# $(NAME)		: $(addprefix objs/, $(OBJS)) libft/libft.a minilibx/libmlx.a
# 			$(CC) $(CFLAGS) -o $(NAME) $^ -Lminilibx -lmlx -framework OpenGL -framework AppKit

# objs/%.o	:	%.c includes/get_next_line.h includes/so_long.h libft/libft.h minilibx/mlx.h minilibx/mlx_int.h minilibx/mlx_new_window.h minilibx/mlx_opengl.h minilibx/mlx_png.h Makefile
# 				@mkdir -p objs
# 				$(CC) $(CFLAGS) -Iincludes -DBUFFER_SIZE=20 -c $< -o $@

			
# clean		:
# 			rm -rf objs/
# 			make clean -C libft
# 			make clean -C minilibx

# fclean		: clean
# 			rm -f $(NAME)
# 			make fclean -C libft

# re			: fclean all

# .PHONY		: all clean re fclean libft minilibx