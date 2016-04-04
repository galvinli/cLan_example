#include <stdio.h>
#include <stdlib.h>



int main(){
	int i=0;
	char A[2][6] = { {"Hello"}, {"World"}};
	char (*a2p)[6] = A;

	for(i=0; i<2; i++) printf( "%s ", A[i]);
	printf("\n");

	for(i=0; i<2; i++) printf( "%s ", a2p[i]);
	printf("\n");

}
