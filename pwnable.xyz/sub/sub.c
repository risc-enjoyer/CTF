#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signal.h>

void sig_handler(void){
	exit(1);
}

void setup(void){
	setvbuf(stdout, NULL, 2, 0);
	setvbuf(stdin, NULL, 2, 0);
	signal(14, sig_handler);
	alarm(60);
}

int main(void){
	unsigned int rsp = 0;   /* [rsp]   */
	unsigned int var_4 = 0; /* [rsp+4] */

	setup();

	printf("1337 input: ");
	scanf("%u %u", &rsp, &var_4);
	if((int)rsp > 0x1336 || (int)var_4 > 0x1336) puts("Sowwy");
	else if((rsp-var_4) == 0x1337) system("cat /flag");

	return 0;
}
