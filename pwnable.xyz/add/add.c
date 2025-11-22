int main(void){
	unsigned long long var_60[10]; /* [rbp-0x60] */
	unsigned long long var_68;     /* [rbp-0x68] */
	unsigned long long var_70;     /* [rbp-0x70] */
	unsigned long long var_78;     /* [rbp-0x78] */
	unsigned int var_7c;           /* [rbp-0x7c] */

	setup();
	for(;;){
		var_78 = 0;
		var_70 = 0;
		var_68 = 0;
		memset(var_60, 0, sizeof(var_60));

		printf("Input: ");
		if((var_7c = scanf("%ld %ld %ld", &var_78, &var_70, &var_68)) != 3) return 0;
		var_60[var_68] = var_70+var_78;
		printf("Result: %ld\n", var_60[var_68]);
	}
}
