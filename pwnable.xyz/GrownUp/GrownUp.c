struct {
	char buf[132]; /* 0x6010e0 */
	char *fmt;     /* 0x601160 */
	char str[8];   /* 0x601168 */
} usr;

void setup(void){
	setvbuf(stdout, NULL, 2, 0);
	setvbuf(stdin, NULL, 2, 0);
	signal(14, handler);
	usr.fmt = &usr.str;
	usr.str[0] = '%';
	usr.str[1] = 's';
	usr.str[2] = '\n';
	alarm(60);
}

int main(void){
	char var_20[16];     /* [rbp-0x20] */
	char *var_28;        /* [rbp-0x28] */
	unsigned int var_2c; /* [rbp-0x2c] */

	setup();
	*(unsigned long long *)buf = 0;
	*(unsigned long long *)(buf+8) = 0;

	printf("Are you 18 years or older? [y/N]: ");
	var_2c = read(0, buf, 16);
	var_20[var_2c-1] = 0;

	if(*var_20 == 'y' || *var_20 == 'Y'){
		var_28 = malloc(132);

		printf("Name: ");
		read(0, var_28, 128);
		strcpy(usr.buf, var_28);
		
		printf("Welcome ");
		printf(usr.fmt, usr.buf);
	}
}
