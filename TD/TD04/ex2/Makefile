CC = gcc
CFLAGS = -Wall -Wextra

NAME = association
SRC = association.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

association.o: association.c association.h
	$(CC) $(CFLAGS) -c association.c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re