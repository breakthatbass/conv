#include "minunit/minunit.h"
#include "../src/conv.h"

#include <string.h>

#define MAXBIN 64


static char b1[MAXBIN]; 
static char b2[MAXBIN]; 
static char b3[MAXBIN]; 
static char b4[MAXBIN]; 
static char b5[MAXBIN]; 


void test_setup(void)
{
	// no tests work properly unless i use strcpy
	strcpy(b1, dtob(65));
	strcpy(b2, dtob(255));
	strcpy(b3, dtob(12345));
	strcpy(b4, dtob(99999999999));
	strcpy(b5, dtob(62738495735));
}

void test_teardown(void)
{
	// nothing
}

MU_TEST(test_string_eq)
{
	mu_assert_string_eq("1000001", b1);
    mu_assert_string_eq("11111111", b2);
	mu_assert_string_eq("11000000111001", b3);
	mu_assert_string_eq("1011101001000011101101110011111111111", b4);
	mu_assert_string_eq("111010011011100000010111100011110111", b5);

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

