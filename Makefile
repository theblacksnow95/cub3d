# ======================
# 📦 Project configuration
# ======================

NAME        = cub3D

# ================== SOURCES ============================================================================

SRCS = src/parsing/cub3d.c src/parsing/format_check.c src/parsing/p_tools.c src/parsing/error_handling.c\
		src/parsing/render_images.c src/parsing/init_var.c src/parsing/color_rgb.c src/parsing/format.c \
		src/parsing/tools_rgb.c src/parsing/read_map.c src/parsing/map_tools.c src/parsing/flood_fill_map.c \
		src/parsing/map_validation.c

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
	@echo "$(RED)Deleting$(RESET) $(YELLOW)BINARY$(RESET)"
	@echo "$(RED)Deleting$(RESET) $(YELLOW)LIBRARIES$(RESET)"
	@rm -rf $(BIN)/$(NAME)
	@$(MAKE) -C $(LIBFT_DIR) -s fclean

test: all
	@echo "$(YELLOW)Running test with map1 example...$(RESET)" && sleep 1
	@echo "\n"
	@./bin/cub3d map1.cub

valgrind: all
	@valgrind  --leak-check=full --show-leak-kinds=all --log-file=.valg_error.log --track-fds=yes -s ./bin/cub3d map1.cub
re: clean all

.SILENT:

.PHONY: all clean fclean re libft mlx