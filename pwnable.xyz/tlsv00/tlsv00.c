void print_flag(void){
	puts("WARNING: NOT IMPLEMENTED");
	if(*(char *)&do_comment == 0){
		printf("Wanna take a survey instead? ");
		if(getchar() == 0x79) do_comment = f_do_comment;
		do_comment();
	}
}

void load_flag(void){
	int fd;    /* [rbp-0x04] */
	int index; /* [rbp-0x08] */
	
	if((fd = open("/flag", 0)) == -1){
		puts("Cant open flag");
		exit(1);
	}
	read(fd, flag, 64);
	for(index = 0; index < 64; index++) flag[index] ^= key[index];
	close(fd);
}

void generate_key(int length){
	char keybuf[0x48]; /* [rbp-0x50] */
	int fd;            /* [rbp-0x54] */
	int index;         /* [rbp-0x58] */

	if(length <= 0 || length > 64) return;
	memset(keybuf, 0, 0x48);
	if((fd = open("/dev/urandom", 0)) == -1){
		puts("Cant open /dev/urandom");
		exit(1);
	}
	read(fd, keybuf, length);
	for(index = 0; index < length; index++){
		if(!keybuf[index]) read(fd, &keybuf[index], 1);
	}
	strcpy(key, keybuf);
	close(fd);
}

int main(void){
	int keylen; /* [rbp-0x04] */
	int opt;    /* [rbp-0x08] */

	setup();
	puts("Muahaha...");

	generate_key(0x3f);

	for(;;){
		print_menu();

		printf("> ");
		if((opt = read_int32()) == 1){
			printf("key len: ");
			keylen = read_int32();
			generate_key(keylen);
		}
		else if(opt == 2) load_flag();
		else if(opt == 3) print_flag(); /* mov eax, 0*/
		else if(opt != 4) puts("Invalid");
	}
}
