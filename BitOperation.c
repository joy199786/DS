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

int main(){
	
	struct u0 uu;
	uu.leading = 2; // 010
	uu.flag1 = 0;
	uu.flag2 = 1;
	uu.trailing = 0;
	printf("sizeof(uu) = %lu\n", sizeof(uu));
	printBinary(*(int*)&uu);
	
	return 0;
}


