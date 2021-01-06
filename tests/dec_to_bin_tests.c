#include "minunit/minunit.h"
#include "../src/conv.h"

static uint64_t n1, n2, n3, n4, n5, n6 = 0;

void test_setup(void)
{
    n1 = btod("01000001");
    n2 = btod("11111111");
    n3 = btod("11000000111001");
    n4 = btod("00000000");
    n5 = btod("1011101001000011101101110011111111111");
    n6 = btod("111010011011100000010111100011110111");
}

void test_teardown(void)
{
    // nothing
}

MU_TEST(test_assert)
{
    mu_assert(n1 == 65, "expected 65");
    mu_assert(n2 == 255, "expected 255");
    mu_assert(n3 == 12345, "expected 12345");
    mu_assert(n4 == 0, "expected 0");
    mu_assert(n5 == 99999999999, "expected 99999999999");
    mu_assert(n6 == 62738495735, "expected 62738495735");
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_assert);
}

int main()
{
    
    MU_RUN_SUITE(test_suite);
	MU_REPORT();
    return MU_EXIT_CODE;
}
