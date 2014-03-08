#include "../vpc_env/env.c"

void adding(uint64_t local_bp, uint64_t local_sp, uint64_t ret_addr);
//register uint64_t local_bp __asm__ ("r12");
//register uint64_t local_sp __asm__ ("r13");

void adding(uint64_t local_sp, uint64_t ret_addr) {

	//register uint64_t local_sp ;
	//register uint64_t local_bp ;
	//*((uint64_t*) (local_sp - 8)) = local_bp;
	uint64_t local_bp = local_sp - 8;
	local_sp = local_sp -0x10;
	*((uint64_t*)(local_bp -8 )) = *((uint64_t*)(local_bp +0x18)) + *((uint64_t*)(local_bp+0x20));
	*((uint64_t*)(local_bp + 0x10)) = *((uint64_t*)(local_bp-8));
	local_sp = local_bp;
	local_bp = *((uint64_t*)local_sp);
	local_sp = local_sp + 8;
	return;
}
