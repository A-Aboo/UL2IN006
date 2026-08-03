CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = prog
OBJS = A.o B.o prog.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

A.o: A.c A.h
	$(CC) $(CFLAGS) -c A.c

B.o: B.c B.h A.h
	$(CC) $(CFLAGS) -c B.c

prog.o: prog.c A.h B.h
	$(CC) $(CFLAGS) -c prog.c

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re