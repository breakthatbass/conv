
#include "minunit/minunit.h"
#include "../src/conv.h"

uint64_t n1, n2, n3, n4, n5 = 0;


void test_setup(void)
{
    n1 = htod("3F");
    n2 = htod("10");
    n3 = htod("A1");
    n4 = htod("A");
    n5 = htod("FFFFF");
}

void test_teardown(void)
{
    // nothing
}

MU_TEST(test_assert) {
	mu_assert(n1 == 63, "3F -> expected 63");
    mu_assert(n2 == 16, "10 -> expected 16");
    mu_assert(n3 == 161, "A1 -> expected 161");
    mu_assert(n4 == 10, "A -> expected 10");
    mu_assert(n5 == 1048575, "FFFFF -> expected 1048575");
}

MU_TEST_SUITE(test_suite)
{
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_assert);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
	MU_REPORT();
    return MU_EXIT_CODE;
}