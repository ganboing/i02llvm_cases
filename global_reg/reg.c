#include <stdint.h>

register uint64_t i0_BP __asm__ ("r14");
register uint64_t i0_SP __asm__ ("r15");
register uint64_t i0_R2 __asm__ ("r12");
register uint64_t i0_R3 __asm__ ("r13");

void test(void) {
	uint64_t a = i0_R2;
	uint64_t b = i0_R3;
	uint64_t c = a;
	a = b;
	b = c;
	i0_R2 = a;
	i0_R3 = b;
}

void add(uint64_t ret_addr) {
	*((uint64_t*) (i0_SP - 8)) = i0_BP;
	i0_BP = i0_SP - 0x10;
	*((uint64_t*) (i0_BP - 8)) = *((uint64_t*) (i0_BP + 0x18))
			+ *((uint64_t*) (i0_BP + 0x20));
	*((uint64_t*) (i0_BP + 0x10)) = *((uint64_t*) (i0_BP - 8));
	i0_SP = i0_BP;
	i0_BP = *((uint64_t*) i0_SP);
	i0_SP = i0_SP + 8;
}
