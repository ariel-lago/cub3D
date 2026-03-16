# Program name
NAME = cub3D

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft -I./minilibx-linux -g

# Directories
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

# COLORS
GREEN	= \033[0;32m
BLUE	= \033[0;36m
RESET	= \033[0m

# LIBFT
LIBFT = $(LIBFT_DIR)/libft.a

# MLX
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

#INC
INC_FILES	= cub3d.h defines.h game.h parse.h utils.h window.h
INCS		= $(addprefix $(INC_DIR)/, $(INC_FILES))

# Source files
SRC_FILES = main.c \
	window.c \
	hooks.c \
	parse.c \
	parse_utils.c \
	utils.c \
	map.c \
	render.c \
	player.c \
	move_player.c \
	player_view.c \
	textures.c \
	minimap.c \
	raycast.c \
	validation.c \
	debug.c
	
SRCS	= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Default target
all: $(NAME)

# Compile Libft first
$(LIBFT):
	@echo "$(BLUE)Building Libft$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null

# Compile MLX
$(MLX):
	@echo "$(BLUE)Building MLX$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1

# Link the program
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

# Compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Clean object files
clean:
	@echo "$(BLUE)Cleaning Objects$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_DIR) > /dev/null
	@make clean -C $(LIBFT_DIR) > /dev/null
	@echo "$(GREEN)Successfully cleaned!$(RESET)"

# Clean everything
fclean: clean
	@echo "$(BLUE)Cleaning Executables$(RESET)"
	@rm -f $(NAME) > /dev/null
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@echo "$(GREEN)Successfully cleaned!$(RESET)"
	
# Recompile
re: fclean all

.PHONY: all clean fclean re mlx
