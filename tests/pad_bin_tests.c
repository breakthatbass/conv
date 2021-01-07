#include "minunit/minunit.h"
#include "../src/helpers.h"

#include <string.h>

#define MAXBIN 64


static char b1[MAXBIN]; 
static char b2[MAXBIN]; 
static char b3[MAXBIN]; 
static char b4[MAXBIN]; 
static char b5[MAXBIN]; 

void test_setup(void)
{
    strcpy(b1, pad_bin("101"));
    strcpy(b2, pad_bin("1001"));
    strcpy(b3, pad_bin("111111"));
    strcpy(b4, pad_bin("11111111111111"));
    strcpy(b5, pad_bin("11111111111111111111111"));
}

void test_teardown(void)
{
    // nothing
}

MU_TEST(test_string_eq)
{
    mu_assert_string_eq(b1, "0101");
    mu_assert_string_eq(b2, "1001");
    mu_assert_string_eq(b3, "00111111");
    mu_assert_string_eq(b4, "0011111111111111");
    mu_assert_string_eq(b5, "011111111111111111111111");
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




/*
// tests for pad_bin function (helper function for btoh)
	assert(strcmp(pad_bin("101"), "0101") == 0);
	assert(strcmp(pad_bin("1001"), "1001") == 0);
	assert(strcmp(pad_bin("111111"), "00111111") == 0);
	assert(strcmp(pad_bin("11111111111111"), "0011111111111111") == 0);
	assert(strcmp(pad_bin("11111111111111111111111"), "011111111111111111111111") == 0);
    */
