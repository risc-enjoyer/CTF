char s[32]; /* 0x601480 */
char *ptr;  /* 0x6014a0 */

void edit_desc(void){
	if(!ptr) ptr = malloc(32);
	printf("desc: ");
	read(0, ptr, 32);
}

void edit_note(void){
	char *var_8;        /* [rbp-0x08] */
	unsigned int var_c; /* [rbp-0x0c] */

	printf("Note len? ");
	var_c = read_int32();
	var_8 = malloc(var_c);

	printf("note: ");
	read(0, var_8, var_c);
	strncpy(s, var_8, var_c);
	free(var_8);
}

int read_int32(void){
	char var_30[32]; /* [rbp-0x30] */

	read(0, var_30, 32);
	return atoi(var_30);
}

int main(void){
	unsigned int var_4; /* [rbp-0x04] */

	setup();

	puts("Note taking 101.");
	for(;;){
		print_menu();
		var_4 = read_int32();
		if(var_4 == 1) edit_note();
		else if(var_4 == 2) edit_desc();
		else if(!var_4) break;
		puts("Invalid");
	}
}
