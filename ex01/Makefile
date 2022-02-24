CC=c++
SRC=
CFLAGS=-Wall -Wextra -Werror -std=c++98
DFLAGS=-g
NAME=

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
