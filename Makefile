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

ENTRY_SRCS = $(SRC_DIR)/main.c

BONUS_ENTRY_SRCS = $(SRC_DIR)/bonus.c

# NOTE: Write there with your hand when you are done!
# SRCS = src/summer.c
# You SHALL NOT include main
# SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS = $(SRC_DIR)/bubble_sort.c \
			 $(SRC_DIR)/func_p.c \
			 $(SRC_DIR)/func_r.c\
			 $(SRC_DIR)/func_rr.c \
			 $(SRC_DIR)/func_s.c \
			 $(SRC_DIR)/render.c \
			 $(SRC_DIR)/sorters.c \
			 $(SRC_DIR)/parse_args.c \
			 $(SRC_DIR)/util_middle.c \
			 $(SRC_DIR)/util_is_integer.c \
			 $(SRC_DIR)/util_minmax.c \
			 $(SRC_DIR)/util_is_sorted.c \
			 $(SRC_DIR)/stack_funcs.c \
			 $(SRC_DIR)/init.c \
			 $(SRC_DIR)/midwheel_algo.c

TEST_SRCS = tests/test_args.c \
						tests/test_utils.c

BONUS_ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_ENTRY_SRCS))
ENTRY_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(ENTRY_SRCS))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SRCS))

all: $(NAME)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS) $(BONUS_ENTRY_OBJS) libft/libft.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJS) $(BONUS_ENTRY_OBJS) -o $@

$(NAME): $(OBJS) $(ENTRY_OBJS) libft/libft.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJS) $(ENTRY_OBJS) -o $@

libft/libft.a:
	make -C libft

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

.PHONY: all bonus test testv run_tester run re_nolog run_vis re clean fclean
-include $(OBJ_DIR)/*.d
# RELEASE Tue Aug 16 18:47:58 +03 2022 REPO_COMMIT: fa2f2c7 LIBFT_COMMIT: d6bb87c
# RELEASE Tue Aug 16 19:08:01 +03 2022 REPO_COMMIT: fa2f2c7 LIBFT_COMMIT: d6bb87c
# RELEASE Tue Aug 16 19:09:21 +03 2022 REPO_COMMIT: fa2f2c7 LIBFT_COMMIT: d6bb87c
# RELEASE Wed Aug 17 12:58:26 +03 2022 REPO_COMMIT: 4995e10 LIBFT_COMMIT: d6bb87c
# RELEASE Wed Aug 17 14:29:40 +03 2022 REPO_COMMIT: 4995e10 LIBFT_COMMIT: d6bb87c
# RELEASE Wed Aug 17 14:32:44 +03 2022 REPO_COMMIT: 4995e10 LIBFT_COMMIT: d6bb87c
# RELEASE Wed Aug 17 14:33:45 +03 2022 REPO_COMMIT: 4995e10 LIBFT_COMMIT: d6bb87c
# RELEASE Wed Aug 17 14:34:48 +03 2022 REPO_COMMIT: 4995e10 LIBFT_COMMIT: d6bb87c
# RELEASE Wed Aug 17 14:36:11 +03 2022 REPO_COMMIT: 4995e10 LIBFT_COMMIT: d6bb87c
