//Exo 1

void check_msb(int num){
	int a;
	a = num >> 31;
	if(a&1 == 1)
		printf("The most significant is 1 (the sign is - / is set)");
	else
		printf("The most significant is 0 (the sign is + / is not set)");
}

//Exo 2

void print_bits(unsigned char byte){
	unsigned char a;
	int i; 
	for(i=0;i<8;i++){
		a = byte>>7-i;
		if(a&1==1)
			printf("1");
		else
			printf("0");
	}
}

