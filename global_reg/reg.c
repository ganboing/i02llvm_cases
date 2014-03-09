#include <stdint.h>

register uint64_t i0_BP __asm__ ("r12");

void test(void)
{
	i0_BP = 0;
}
