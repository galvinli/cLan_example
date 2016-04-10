#include <stdio.h>
#include <stdlib.h>

int main(){
	int n=0;
	int b=20;
	char A[11]={};
	for(n=0; n<10; n++){
		A[n]='A';
		printf("%d\n",n);
		printf("A: %s\n", A);
	}	
	b-=n;
	printf("A:%s, n=%d b=%d\n", A, n, b);
	return 0;
}
