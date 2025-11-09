# ======================
# 📦 Project configuration
# ======================

NAME        = cub3D

# Source files
SRC         = src/main.c \
			  src/events/game_start.c

# Directories
INC         = include
LIBFT_DIR   = libraries/libft
MLX_DIR     = minilibx/minilibx-linux

# Compilation
OBJ         = $(SRC:.c=.o)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ======================
# 🛠️ Rules
# ======================

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Linking $(NAME)..."
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

# Build object files
%.o: %.c
	@echo "🧩 Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ======================
# 🧱 Libraries
# ======================

libft:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	@$(MAKE) -C $(MLX_DIR)

.PHONY: all clean fclean re libft mlx
