# Program name
NAME = cub3d

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -I./minilibx-linux -g

# LIBFT
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source files - LIST YOUR .c FILES HERE
SRCS = srcs/main.c \
       srcs/window.c \
       srcs/hooks.c \
       srcs/parse.c \
       srcs/utils.c \
	   srcs/map.c \
	   srcs/render.c \
	   srcs/validation.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Compile Libft first
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link the program
$(NAME): $(LIBFT) $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Clean object files
clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean

# Recompile
re: fclean all

.PHONY: all clean fclean re
