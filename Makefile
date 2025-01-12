NAME        = so_long

# Directories
SRC_DIR     = src
INC_DIR     = includes
LIBFT_DIR   = extra_libs/libft_gnl
PRINTF_DIR  = extra_libs/ft_printf
MLX_DIR     = extra_libs/mlx
MAPS_DIR    = maps
TEX_DIR     = textures

# Source files
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/game_init.c \
              $(SRC_DIR)/game_loop.c \
              $(SRC_DIR)/map_check.c \
              $(SRC_DIR)/map_parse.c \
              $(SRC_DIR)/path_check.c \
              $(SRC_DIR)/render.c

OBJS        = $(SRCS:.c=.o)

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I$(INC_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)

# Libraries to link
LIBFT       = $(LIBFT_DIR)/libft.a
FT_PRINTF   = $(PRINTF_DIR)/libftprintf.a
MLX         = $(MLX_DIR)/libmlx.a

# MLX Flags for Linux
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)       # Build libft + GNL
	@$(MAKE) -C $(PRINTF_DIR)      # Build ft_printf
	@$(MAKE) -C $(MLX_DIR)         # Build MiniLibX
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS)
	@echo "Compiled $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@$(MAKE) clean -C $(MLX_DIR) || true
	rm -f $(OBJS)
	@echo "Cleaned object files."

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)
	@echo "Removed $(NAME)."

re: fclean all

.PHONY: all clean fclean re
