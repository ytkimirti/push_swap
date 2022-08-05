NAME = push_swap

# NOTE: Add -Werror here before pushing to intra
CFLAGS = -Wall -Wextra -Ilibft
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

# NOTE: Write there with your hand when you are done!
# SRCS = src/summer.c
# You SHALL NOT include main
# SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS = src/bubble_sort.c \
			 src/check_args.c \
			 src/func_p.c \
			 src/func_r.c\
			 src/func_rr.c \
			 src/func_s.c \
			 src/render.c \
			 src/sort_triple.c \
			 src/util_minmax.c \
			 src/util_middle.c \
			 src/midwheel_algo.c

TEST_SRCS = tests/test_args.c \
						tests/test_utils.c

ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(ENTRY_SRCS))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SRCS))

all: $(NAME)

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

clean:
	rm -rf $(OBJ_DIR) $(TEST_DIR)/bin

fclean: clean
	rm -f $(NAME)
