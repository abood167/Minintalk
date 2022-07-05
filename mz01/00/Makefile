NAME = server

NAME1 = client 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c

OBJS = $(SRCS:.c=.o)

all: ${NAME} ${NAME1} ${OBJS}

$(NAME):
	@make -C ./libft
	$(CC) $(CFLAGS)  server.c -Llibft -lft -o $@

$(NAME1):
	@make -C ./libft
	$(CC) $(CFLAGS)  client.c -Llibft -lft -o $@

clean:
	make -C ./libft clean
	rm -f  $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME) $(NAME1)


re: fclean all

.PHONY: re clean fclean all