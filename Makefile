# ================== VARIABLES ==========================================================================

NAME = cub3d
CC = gcc

# ================== SOURCES ============================================================================

SRC = src/parsing/cub3d.c


# ================== DIRECTORIES ========================================================================

INC = include
LIBFT_DIR = $(INC)/libft
MLX_DIR = $(INC)/ml_linux
BIN = bin
OBJECTS = obj

# ================== FLAGS ==============================================================================


C_FLAGS = -Wall -Wextra -Werror -g -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR)
ML_FLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lm

# =============== LIBRARIES =============================================================================

LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

# =============== OBJECTS COMPILATION ===================================================================

OBJ = $(SRC:$(SRC)/%.c=$(OBJECTS)/%.o)


#================= COMPILATION RULES ====================================================================

all: $(BIN)/$(NAME)

$(BIN)/$(NAME): $(OBJ)
	@mkdir -p $(BIN)
	$(CC) $(C_FLAGS) -I$(INC) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)


$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(C_FLAGS) $(OBJ) -o $(NAME) $(ML_FLAGS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJECTS)/$(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: clean all

.PHONY: all clean fclean re
