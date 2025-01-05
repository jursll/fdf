# Nom du projet final
NAME = fdf.a

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INCLUDES = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)

# Fichiers sources et objets pour le projet FdF
SRC = fdf_main.c fdf_draw_map.c fdf_read_map.c fdf_draw_line.c
OBJ = $(SRC:.c=.o)

# Règles principales
all: $(LIBFT) $(MLX) $(NAME)

# Compile la libft
$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Compile la MiniLibX
$(MLX):
	@echo "Compiling MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

# Compile le projet FdF
$(NAME): $(OBJ)
	@echo "Creating $(NAME)..."
	@ar rcs $(NAME) $(OBJ) $(LIBFT) $(MLX)

# Compile les fichiers .c en .o
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage des objets du projet FdF
clean:
	@echo "Cleaning FdF objects..."
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

# Nettoyage complet
fclean: clean
	@echo "Cleaning everything..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Recompile tout
re: fclean all

.PHONY: all clean fclean re
