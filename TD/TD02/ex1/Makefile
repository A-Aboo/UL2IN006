CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = exercice1
OBJS = liste.o main.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

liste.o: liste.c liste.h
	$(CC) $(CFLAGS) -c liste.c

main.o: main.c liste.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re