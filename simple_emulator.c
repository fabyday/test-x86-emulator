#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <mach-o/loader.h>

#define MEM_SIZE (1024*1024*64)
#define FAKE_RETURN 0xffff



typedef struct {
	uint64_t rax;
	uint64_t rbx;
	uint64_t rcx;
	uint64_t rdx;
	uint64_t rsi;
	uint64_t rdi;
	uint64_t rsp;
	uint64_t rbp;
	uint64_t rip;
} CPU;

uint8_t mem[MEM_SIZE];
static void write64(uint64_t addr, uint64_t value){
	if(addr + 8 > MEM_SIZE){
		printf("write out of bounds : %08lx\n", addr);
		exit(1);
	}
	memcpy(mem + addr, &value, 8);
}

static uint64_t read64(uint64_t addr){
	if(addr + 8 > MEM_SIZE){
		printf("read out of bounds : %08lx\n", addr);
		exit(1);
	}
	uint64_t value;
	memcpy(&value, mem + addr, 8);
	return value;
}



int main(){

const char* program = "main.out";




FILE *f = fopen(program, "rb");
if(!f){
	perror("fopen");
	return 1;
}

struct mach_header_64 header; 
fread(&header, 1, sizeof(header), f);


if(header.magic != MH_MAGIC_64){
	printf("not mach-o : %08x\n", header.magic);
	return 1;
}




}
