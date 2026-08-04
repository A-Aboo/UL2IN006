CC = gcc
CFLAGS = -Wall -Wextra

NAME = formation
SRC = formation.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

formation.o: formation.c formation.h
	$(CC) $(CFLAGS) -c formation.c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re