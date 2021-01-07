#include "minunit/minunit.h"
#include "../src/conv.h"

#include <string.h>

#define MAXHEX 12

static char h1[MAXHEX];
static char h2[MAXHEX];
static char h3[MAXHEX];
static char h4[MAXHEX];
static char h5[MAXHEX];


void test_setup(void)
{
    strcpy(h1, btoh("101"));
    strcpy(h2, btoh("1001"));
    strcpy(h3, btoh("111111"));
    strcpy(h4, btoh("11111111111111111111"));
    strcpy(h5, btoh("10101011110011011110"));
}

void test_teardown(void)
{
    // nothing
}

MU_TEST(test_string_eq)
{
    mu_assert_string_eq(h1, "5");
    mu_assert_string_eq(h2, "9");
    mu_assert_string_eq(h3, "3F");
    mu_assert_string_eq(h4, "FFFFF");
    mu_assert_string_eq(h5, "ABCDE");
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_string_eq);
}


int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}