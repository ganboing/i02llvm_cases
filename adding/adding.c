#include "../vpc_env/env.c"



void adding(uint64_t ret_addr);

void adding(uint64_t ret_addr) {
	*((uint64_t*) (sp - 8)) = bp;
	bp = sp - 8;
	sp = sp -0x10;
	*((uint64_t*)(bp -8 )) = *((uint64_t*)(bp +0x18)) + *((uint64_t*)(bp+0x20));
	*((uint64_t*)(bp + 0x10)) = *((uint64_t*)(bp-8));
	sp = bp;
	bp = *((uint64_t*)sp);
	sp = sp + 8;
	return;
}
