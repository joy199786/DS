# include <stdio.h>
# include <stdlib.h>


struct u0{
	unsigned int leading: 3;
	unsigned int flag1: 1;
	unsigned int flag2: 1;
	int trailing: 27; //27 + 3 +1 +1 = 32
};

void printBinary(unsigned int number){
	unsigned mask = 1u<<31;
	for(; mask; mask >>=1){
		printf("%d", number &mask? 1:0);
	}
	printf("\n");
}

void printInBinary(int num){
	unsigned mask = 1<<31;
	//mask = ~mask;
	//printf("%d", mask);
	for( ; mask; mask>>=1){
		printf("%d", num&mask?1:0);
	}
	printf("\n");
}

int main(){
	
	long ans = 0;
	short a = 0x1234;
	short b = 0x5600;
	ans += a << 16;
	printf("%08x\n", ans);
	ans += b << 0;
	printf("%08x\n", ans);
	ans += (b >> 2) + 0x22;
	printf("%08x\n", ans);
	printInBinary(ans);
	printf("%08x", ans);
	int n ;
	scanf("%d", &n);
	printInBinary(n);
	
	
	struct u0 uu;
	uu.leading = 2; // 010
	uu.flag1 = 0;
	uu.flag2 = 1;
	uu.trailing = 0;
	printf("sizeof(uu) = %lu\n", sizeof(uu));
	printBinary(*(int*)&uu);
	
	return 0;
}


