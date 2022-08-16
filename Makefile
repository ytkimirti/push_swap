NAME = push_swap
BONUS_NAME = checker

# NOTE: Add -Werror here before pushing to intra
CFLAGS = -MD -Wall -Wextra -Ilibft -g
LDFLAGS = -Llibft
LDLIBS = -lft

# NOTE: You have to have libcriterion.a file in your LIBRARY_PATH and criterion.h file in C_INCLUDE_PATH
# If you installed them with homebrew, add them to these env variables in your shell config
TESTFLAGS = -lcriterion

CC = gcc
SHELL = /bin/sh

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

ENTRY_SRCS = src/main.c

BONUS_ENTRY_SRCS = src/bonus.c

# NOTE: Write there with your hand when you are done!
# SRCS = src/summer.c
# You SHALL NOT include main
# SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS = src/bubble_sort.c \
			 src/func_p.c \
			 src/func_r.c\
			 src/func_rr.c \
			 src/func_s.c \
			 src/render.c \
			 src/sorters.c \
			 src/parse_args.c \
			 src/util_middle.c \
			 src/util_is_integer.c \
			 src/util_minmax.c \
			 src/util_is_sorted.c \
			 src/stack_funcs.c \
			 src/init.c \
			 src/midwheel_algo.c

TEST_SRCS = tests/test_args.c \
						tests/test_utils.c

BONUS_ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_ENTRY_SRCS))
ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(ENTRY_SRCS))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SRCS))

all: $(NAME)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS) $(BONUS_ENTRY_OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJS) $(BONUS_ENTRY_OBJS) -o $@

$(NAME): $(OBJS) $(ENTRY_OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJS) $(ENTRY_OBJS) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(TEST_DIR)/bin:
	mkdir $(TEST_DIR)/bin

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(OBJS) | $(TEST_DIR)/bin
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $(TESTFLAGS) $(OBJS) $< -o $@

test: $(TEST_BINS)
	for test in $(TEST_BINS) ; do ./$$test ; done

testv: $(TEST_BINS)
	for test in $(TEST_BINS) ; do ./$$test --verbose ; done

run_tester: CFLAGS += -DLOG=false
run_tester: re push_swap_tester
	@echo "======== LIMIT IS 3 =============="
	@bash push_swap_tester/tester.sh ./ 3 5 --quiet
	@echo "======== LIMIT IS 12 =============="
	@bash push_swap_tester/tester.sh ./ 5 5 --quiet
	@echo "======== LIMIT IS 700 =============="
	@bash push_swap_tester/tester.sh ./ 100 5 --quiet
	@echo "======== LIMIT IS 5500 =============="
	@bash push_swap_tester/tester.sh ./ 500 5 --quiet

run: all
	./push_swap 2 3 5 12 10 6 9 7 4 1 8 11

re_nolog: CFLAGS += -DLOG=false
re_nolog: re

run_vis: CFLAGS += -DLOG=false
run_vis: re
	@python3 ./python_visualizer.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

re: fclean all

clean:
	rm -rf $(OBJ_DIR) $(TEST_DIR)/bin

fclean: clean
	rm -f $(NAME)

-include $(OBJ_DIR)/*.d
