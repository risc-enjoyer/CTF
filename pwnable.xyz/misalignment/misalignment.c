int main(void){
	long long s[19];     /* [rbp-0xa0] */
	unsigned int var_a4; /* [rbp-0xa4] */

	setup();
	memset((unsigned char *)s, 0, 0x98);
	*(unsigned long long *)(s+0xf) = 0xdeadbeef;

	while((var_a4 = scanf("%ld %ld %ld", &s[4], &s[5], &s[6])) == 3){
		if(s[6] > 9 || s[6] < -7) break;
		s[1+(s[6]+6)] = s[5]+s[4];
		printf("Result: %ld\n", s[1+(s[6]+6)]);
	}
	if(*(unsigned long long *)(s+0xf) == 0x0b000000b5) win();
	return 0;

}
