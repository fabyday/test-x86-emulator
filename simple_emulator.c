#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <mach-o/loader.h>
int main(){

const char* program = "a.out";




FILE *f = fopen(program, "rb");
if(!f){
	perror("fopen");
	return 1;
}

struct mach_header_64 header; 
fread(&header, 1, sizeof(header), f);


if(header.magic != MH_CIGAM_64){
	printf("not mach-o:");
	printf("%d", header.magic);
	return 1;
}


}
