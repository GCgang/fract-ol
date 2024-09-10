CC=cc
CFLAGS= -Wall -Wextra -Werror
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

NAME = fractol
SOURCES = draw.c\
		  fractal.c\
		  help.c\
		  hook.c\
		  main.c\
		  util.c\

OBJS = $(SOURCES:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
