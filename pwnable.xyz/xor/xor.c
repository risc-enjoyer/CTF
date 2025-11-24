unsigned long long result[10]; /* 0x202200 */

void main(void){
	unsigned long long var_10; /* [rbp-0x10] */
	unsigned long long var_18; /* [rbp-0x18] */
	unsigned long long var_20; /* [rbp-0x20] */
	unsigned int var_24;       /* [rbp-0x24] */

	puts("The Poopolator");
	setup();

	for(;;){
		var_10 = 0;
		printf("> \u0001f4a9  ");
		var_24 = scanf("%ld %ld %ld", &var_20, &var_18, &var_10);
		if(!var_20 || !var_18 || !var_10 || var_10 > 9 || var_24 != 3) exit(1);
		result[var_10] = var_20^var_18;
		printf("Result: %ld\n");
	}
}
