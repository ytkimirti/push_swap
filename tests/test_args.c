#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include "../src/vars.h"
#include "../src/utils.h"
#include "../src/vars.h"
#include "../src/vars.h"
#include <signal.h>

Test(is_integer, positive)
{
	cr_assert(is_integer("123"));
	cr_assert(is_integer("9231"));
	cr_assert(is_integer("021"));
	cr_assert(is_integer("000"));
}

Test(is_integer, negative)
{
	cr_assert(is_integer("-123"));
	cr_assert(is_integer("-9231"));
	cr_assert(is_integer("-021"));
	cr_assert(is_integer("-000"));
}

Test(is_integer, weird)
{
	cr_assert(not (is_integer("one")));
	cr_assert(not (is_integer("two three")));
	cr_assert(not (is_integer("  asd  ")));
	cr_assert(not (is_integer("  12  ")));
	cr_assert(not (is_integer("++a")));
	cr_assert(not (is_integer("++123")));
	cr_assert(not (is_integer("--1-23")));
	cr_assert(not (is_integer("-42-+")));
	cr_assert(not (is_integer("-320 ")));
	cr_assert(not (is_integer("0 32")));
}

Test(is_integer, limits)
{
	// INT_MAX is 2147483647
	cr_assert(is_integer("2147483646"));
	cr_assert(is_integer("2147483647"));
	cr_assert(not (is_integer("2147483648")));
	cr_assert(not (is_integer("3147483648")));
	cr_assert(not (is_integer("5147483648")));

	cr_assert(is_integer("-2147483646"));
	cr_assert(is_integer("-2147483647"));
	cr_assert(is_integer("-2147483648"));
	cr_assert(not (is_integer("-3147483648")));
	cr_assert(not (is_integer("-5147483648")));
}
//
// Test(check_args, normal)
// {
// 	int argc = 6;
// 	const char *argv[] = {
// 		"push_swap",
// 		"12",
// 		"3",
// 		"4",
// 		"0",
// 		"-23"
// 	};
//
// 	int result = check_args(argc, argv);
// 	cr_expect(eq(int, result, 5));
// }
//
// Test(check_args, empty)
// {
// 	return;
// 	int argc = 1;
// 	const char *argv[] = {
// 		"push_swap",
// 	};
//
// 	int result = check_args(argc, argv);
// 	cr_expect(eq(int, result, 7));
// }
//
// Test(check_args, joined)
// {
// 	int argc = 6;
// 	const char *argv[] = {
// 		"push_swap",
// 		"12 32",
// 		"3 25",
// 		"4",
// 		"0",
// 		"-23"
// 	};
//
// 	int result = check_args(argc, argv);
// 	cr_expect(eq(int, result, 7));
// }
//
// Test(check_args, joined2)
// {
// 	int argc = 4;
// 	const char *argv[] = {
// 		"push_swap",
// 		"12 32 21 23",
// 		"",
// 		"",
// 	};
//
// 	int result = check_args(argc, argv);
// 	cr_expect(eq(int, result, 4));
// }
//
// Test(check_args, joined3, .exit_code = 1, .init = cr_redirect_stderr)
// {
// 	int argc = 3;
// 	const char *argv[] = {
// 		"push_swap",
// 		"-32a 38a",
// 		"-a++- 32a 329x-",
// 	};
//
// 	int result = check_args(argc, argv);
// 	cr_expect(eq(int, result, 5));
// }
//
// Test(check_args, error, .exit_code = 1, .init = cr_redirect_stderr)
// {
// 	int argc = 3;
// 	const char *argv[] = {
// 		"push_swap",
// 		"-32a 38a",
// 		"-a++- 32a 329x-",
// 	};
//
// 	int result = check_args(argc, argv);
// 	cr_expect(eq(int, result, 5));
// }
// Test(check_args, error2, .exit_code = 0)
// {
// 	int argc = 1;
// 	const char *argv[] = {
// 		"push_swap",
// 	};
//
// 	check_args(argc, argv);
// }
// Test(check_args, error3, .exit_code = 1, .init = cr_redirect_stderr)
// {
// 	int argc = 2;
// 	const char *argv[] = {
// 		"push_swap",
// 		"hello world"
// 	};
//
// 	check_args(argc, argv);
// }
// Test(check_args, error4, .exit_code = 1, .init = cr_redirect_stderr)
// {
// 	int argc = 4;
// 	const char *argv[] = {
// 		"push_swap",
// 		"123",
// 		"",
// 		"",
// 		""
// 	};
//
// 	check_args(argc, argv);
// }
