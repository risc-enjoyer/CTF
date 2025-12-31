char xor_str[32] = { /* 0x400b04 */
	0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec, 0x50,
	0x64, 0x48, 0x8b, 0x04, 0x25, 0x28, 0x00, 0x00,
	0x00, 0x48, 0x89, 0x45, 0xf8, 0x31, 0xc0, 0xe8,
	0x24, 0xfe, 0xff, 0xff, 0x48, 0x8d, 0x45, 0xc0
};
char key[32] = { /* 0x401d28 */
	0x11, 0xde, 0xcf, 0x10, 0xdf, 0x75, 0xbb, 0xa5,
	0x43, 0x1e, 0x9d, 0xc2, 0xe3, 0xbf, 0xf5, 0xd6,
	0x96, 0x7f, 0xbe, 0xb0, 0xbf, 0xb7, 0x96, 0x1d,
	0xa8, 0xbb, 0x0a, 0xd9, 0xbf, 0xc9, 0x0d, 0xff
};

int auth(char *name){         /* [rbp-0x48] */
	char buf[32];         /* [rbp-0x30] */
	unsigned long passed; /* [rbp-0x34] */
	unsigned long index;  /* [rbp-0x38] */
	char cur_byte;        /* [rbp-0x39] */

	memset(buf, 0, 32);
	for(index = 0; index < 32; index++){
		cur_byte = (name[index]<<4)|(name[index]>>4);
		buf[index] = xor_str[index] ^ cur_byte;
	}
	if((passed = strncmp(buf, key, 0x20)) == 0) return 1;
	return 0;
}

void main(void){
	struct {
		unsigned long __unused;
		int age;                /* [rbp-0x10] */
		char nationality[16];
		char name[32];
	} user;                         /* [rbp-0x40] */
	unsigned long option;           /* [rbp-0x44] */
	
	setup();
	memset(&user, 0, 56);

	for(;;){
		print_menu();
		option = read_int32();
		if(option == 1){
			printf("name: ");
			scanf("%32s", user.name);
		}else if(option == 2){
			printf("nationality: ");
			scanf("%24s", user.nationality);
		}else if(option == 3){
			printf("age: ");
			scanf("%d", user.age);
		}else if(option == 4){
			if(auth(&user) == 0) win();
		}else puts("Invalid");
	}
}
