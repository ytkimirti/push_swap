#include <stdio.h>
#include "minunit.h"

int tests_run = 0;

int foo = 0;
int bar = 4;

# define RED "\e[0;31m"
# define RST "\e[0m"
# define GRN "\e[0;32m"

static char *test_foo() {
	mu_assert("error: foo != 7", foo == 7);
	return (NULL);
}

static char *all_tests() {
	mu_run_test(test_foo);
	return (NULL);
}

int main() {
	char *result = all_tests();
	if (result != NULL)
		printf("%s\n", result);
	else
		printf(GRN "All tests passed!\n" RST);
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}
