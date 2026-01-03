int main(void){
	void *ow;        /* [rsp+0x08] */
	void *ptr;       /* [rsp+0x10] */
	char buf[48];    /* [rsp+0x18] */
	int result;      /* eax */

	setup();
	ptr = malloc(0x40);

	for(;;){
		printf("> ");
		
		memset(&buf, 0, 48);
		read(0, buf, 48);
		result = atoi(buf);

		if(result == 1) read(0, ptr, 32);
		else if(result == 2) printf("%p\n", &ptr);
		else if(result == 3) if(obj.limit < 2) *(&var_8) = *(__int128 *)ptr;
		else if(result == 0){
			if(!ptr) exit(1);
			free(ptr);
			break;
		}else puts("Invalid");
	}
	return 0;
}
