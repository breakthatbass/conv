#include "minunit/minunit.h"
#include "../src/helpers.h"
#include <stdlib.h>

#define WORDSIZ 25

static char s1[WORDSIZ] = "hello";
static char s2[WORDSIZ] = "racecar";
static char s3[WORDSIZ] = "I'm hungry";
static char s4[WORDSIZ] = "Hi, Hungry, I'm dad";
static char s5[WORDSIZ] = "x";


void test_setup(void)
{
    reverse(s1);
    reverse(s2);
    reverse(s3);
    reverse(s4);
    reverse(s5);
}

void test_teardown(void)
{
    // nothing
}

MU_TEST(test_string_eq){
	mu_assert_string_eq("olleh", s1);
    mu_assert_string_eq("racecar", s2);
    mu_assert_string_eq("yrgnuh m'I", s3);
    mu_assert_string_eq("dad m'I ,yrgnuH ,iH", s4);
    mu_assert_string_eq("x", s5);
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