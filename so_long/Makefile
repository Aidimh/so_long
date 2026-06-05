CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft
GNL_DIR = ./get_next_line

SRCS_CORE = main.c check_for_map.c exit_status.c free.c \
            initialize_game.c load_images.c \
            check_for_valid_path.c is_valid_ber_map.c

SRCS_GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRCS_LIBFT = $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_putchar_fd.c \
             $(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_strchr.c \
             $(LIBFT_DIR)/ft_strcmp.c $(LIBFT_DIR)/ft_split.c \
             $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strlen.c \
             $(LIBFT_DIR)/ft_substr.c

SRCS = $(SRCS_CORE) $(SRCS_GNL) $(SRCS_LIBFT)

OBJS = $(SRCS:.c=.o)

NAME = so_long

LIBS = -L$(MLX_DIR) -lmlx -lm -lz -L$(LIBFT_DIR) -lft
ifeq ($(shell uname), Linux)
    LIBS += -lX11 -lXext
endif

INCS = -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
