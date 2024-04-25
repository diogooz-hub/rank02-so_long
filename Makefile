NAME = so_long
CC = gcc
#CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
MLX_DIR = mlx_linux
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11
#MLX_DIR = mlx
#MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit


SRC = so_long.c build.c check_map.c check_play.c controls.c map.c errors_and_exit.c
OBJS = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -O3 -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft $(MLXFLAGS)


all: $(NAME)

clean:
	@echo "cleaning"
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@echo "cleaning everyfuckinthing"
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
