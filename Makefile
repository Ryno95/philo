NAME=philosophers
TEST_NAME=test_philo
CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS= src/parser.c

TEST_SRCS= 	Unit_tests/main.c\
			Unit_tests/tests.c\
			Unit_tests/parser_tests.c\

all:$(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) main.c $(SRCS) -o $(NAME)

run: $(NAME)
	./run.sh
test: $(SRCS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(TEST_SRCS) -o $(TEST_NAME)
	./$(TEST_NAME)

acceptence: $(NAME)
	./Acceptence_test/acceptence.sh

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(NAME)
	rm -f $(TEST_NAME)
	rm -f *.o

re: fclean all

fclean: clean