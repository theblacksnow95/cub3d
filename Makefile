# ================== VARIABLES ==========================================================================

NAME = cub3d
CC = gcc

# ================== SOURCES ============================================================================

SRCS = src/parsing/cub3d.c src/parsing/format_check.c src/parsing/p_tools.c src/parsing/error_handling.c\
		src/parsing/render_images.c src/parsing/init_var.c src/parsing/color_rgb.c src/parsing/format.c \
		src/parsing/tools_rgb.c

# ================== DIRECTORIES ========================================================================

INC = include
LIBS = libraries
LIBFT_DIR = $(LIBS)/libft
MLX_DIR = $(LIBS)/ml_linux
BIN = bin
OBJECTS = obj

# ================== FLAGS ==============================================================================


C_FLAGS = -Wall -Wextra -Werror -g -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR)
ML_FLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lz -lm

# =============== LIBRARIES =============================================================================

LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

# =============== OBJECTS COMPILATION ===================================================================

OBJ_PARS = $(SRCS:src/parsing/%.c=$(OBJECTS)/%.o)



#================= COLORS ===============================================================================

#ANSI COLORS
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m


#================= COMPILATION RULES ====================================================================

all: $(BIN)/$(NAME)


# main target NAME compilation rule
$(BIN)/$(NAME): $(OBJ_PARS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(YELLOW)Compiling binary ...$(RESET)"
	@$(CC) $(C_FLAGS) $(OBJ_PARS) -o $(BIN)/$(NAME) $(ML_FLAGS) 2> .error_log && \
	(echo "$(YELLOW)Binary compiled: $(GREEN)[OK]$(RESET)") || \
	(echo "$(YELLOW)Error compiling : $(RED) [KO]$(RESET)" && cat .error_log && rm -rf .error_log && exit 1)


#rule to compile the OBJECTS
$(OBJECTS)/%.o:src/parsing/%.c
	@mkdir -p $(OBJECTS)
	@$(CC) $(C_FLAGS) -c $< -o $@  2> .error_log && \
	(echo "$(YELLOW)Objects parsing compiled: $(GREEN)[OK]$(RESET)") || \
	(echo "$(YELLOW)Error compiling obj: $(RED)[KO]$(RESET)" && cat < .error_log && rm -rf .error_log && exit 1)

$(LIBFT_LIB):
	@echo "$(YELLOW)Building $(RED)LIBFT$(RESET) $(YELLOW)library...$(RESET)"
	@$(MAKE)  -C $(LIBFT_DIR)  2> error_log && \
	(echo "$(YELLOW)Libft: $(GREEN)[OK]$(RESET)") || \
	(echo "$(YELLOW)Libft: $(RED)[KO]$(RESET)" && cat .error_log && rm -f .error_log && exit 1)

$(MLX_LIB):
	@echo "$(YELLOW)Building $(RED)MLX_LINUX $(YELLOW)library..."
	@$(MAKE) -C $(MLX_DIR) -s 2> .error_log && \
	(echo "$(YELLOW)MLX: $(GREEN)[OK]$(RESET)") || \
	(echo "$(YELLOW)MLX: $(RED)[KO]$(RESET)" && cat .error_log && rm -f .error_log && exit 1)

clean:
	@rm -rf $(OBJ_PARS)
	@$(MAKE) -C $(LIBFT_DIR) -s clean
	@$(MAKE) -C $(MLX_DIR) -s clean
	@echo "$(YELLOW)CLEANING $(RED)OBJECTS$(RESET) $(YELLOW)FROM LIBS...$(RESET)"

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
	@valgrind  --leak-check=full --show-leak-kinds=all -s ./bin/cub3d map1.cub

re: clean all

.SILENT:

.PHONY: all clean fclean re test valgrind
