NAME=philo
TEST_NAME=test_philo
CC=gcc
CFLAGS=-Wall -Wextra -Werror
CFLAGS_ASAN=$(CFLAGS) -fsanitize=leak
LDFLAGS=-lpthread

SRCS= 	src/parser.c src/parser_utils.c src/philosophers.c\
		src/ft_time.c src/handle_threads.c src/actions.c src/last_supper.c

TEST_SRCS= 	Unit_tests/main.c\
			Unit_tests/tests.c\
			Unit_tests/parser_tests.c\
			Unit_tests/create_philos_tests.c\
			Unit_tests/ft_time_tests.c\

all:$(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) main.c $(SRCS) $(LDFLAGS) -o $(NAME)

run: $(NAME)
	./run.sh

test: $(SRCS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(TEST_SRCS) $(LDFLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)

acceptence: $(NAME)
	./Acceptence_test/acceptence.sh
	./Acceptence_test/run_norminette.sh

run_asan: $(SRCS)
	@$(CC) $(CFLAGS_ASAN) main.c $(SRCS) $(TEST_FILES) -o $(NAME)
	./run.sh

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(NAME)
	rm -f $(TEST_NAME)
	rm -f *.o
	rm -f norminette_result

re: fclean all

fclean: clean