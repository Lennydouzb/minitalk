NAME = client
NAME2 = server
CC = cc

PRINTF_DIR = srcs/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Wextra -Werror

SRCSC = srcs/client/main.c \

SRCSS = srcs/server/main.c \
	   
OBJSC = $(SRCSC:.c=.o)

OBJSS = $(SRCSS:.c=.o)


all: $(NAME)

$(NAME): $(OBJSC) $(PRINTF) $(LIBFT) $(NAME2)
	$(CC) $(CFLAGS) $(OBJSC) $(PRINTF) $(LIBFT) -o $(NAME) -g

$(NAME2): $(OBJSS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSS) $(PRINTF) $(LIBFT) -o $(NAME2) -g

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

fclean: clean
	rm -f $(NAME) $(NAME2) && $(MAKE) fclean -C $(LIBFT_DIR) && $(MAKE) fclean -C $(PRINTF_DIR)


clean:
	rm -f $(OBJSS) $(OBJSC) && $(MAKE) clean -C $(LIBFT_DIR) && $(MAKE) clean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
