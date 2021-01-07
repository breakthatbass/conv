#include "minunit/minunit.h"
#include "../src/conv.h"

#include <stdlib.h>

static const char *b1;
static const char *b5;

void test_setup(void)
{
    b1 = dtob(65);
    /*
    b2 = dtob(255);
    b3 = dtob(12345);
    b4 = dtob(99999999999);
    */
    //b5 = dtob(62738495735);
}

void test_teardown(void)
{
    // nothing
}

/*******

// decimal to binary tests
	assert(strcmp(dtob(65), "1000001") == 0);
	assert(strcmp(dtob(255), "11111111") == 0);
	assert(strcmp(dtob(12345), "11000000111001") == 0);
	assert(strcmp(dtob(99999999999), "1011101001000011101101110011111111111") == 0);
	assert(strcmp(dtob(62738495735), "111010011011100000010111100011110111") == 0);

    *********/

MU_TEST(test_string_eq)
{
	mu_assert_string_eq(b1, "1000001");
    //mu_assert_string_eq(b5, "111010011011100000010111100011110111");
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

