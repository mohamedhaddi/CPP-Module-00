CC=c++
SRC=main.cpp PhoneBook.class.cpp Contact.class.cpp
CFLAGS=-Wall -Wextra -Werror -std=c++98
DFLAGS=-g
NAME=phonebook

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -Wvexing-parse $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
