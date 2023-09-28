NAME = so_long

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

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx.a

all: libft minilibx $(NAME)

libft:
	$(MAKE) -C libft

minilibx:
	$(MAKE) -C minilibx

# Règle de construction de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm -lbsd

# Pour macOS, ajout des options -framework
ifeq ($(shell uname -s),Darwin)
    $(NAME): $(OBJS)
        $(CC) $(CFLAGS) -o $@ $^ -Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm -lbsd -framework OpenGL -framework AppKit
endif

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -Iincludes -DBUFFER_SIZE=20 -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft minilibx